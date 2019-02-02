#include "playercontrols.h"
#include "ui_playercontrols.h"

#include <QFileInfo>
#include <QTime>
#include <QMessageBox>

PlayerControls::PlayerControls(QWidget *parent) :
     QWidget(parent),
    ui(new Ui::PlayerControls)
{
    blockState = BlockState::A;
    ui->setupUi(this);

    setLayout(ui->mainLayout);

    ui->frameMain->setLayout(ui->lyFrameMain);
    ui->frameTimeControl->setLayout(ui->lyTimeControl);
    ui->frameABControl->setLayout(ui->lyABControl);

    ui->frameABControl->hide();

    player = new NMediaPlayer();
    playlist = new QMediaPlaylist();
    player->setPlaylist(playlist);

    btc = new BlockTimeControls();
    plv = new PlayListView();

    connect(ui->tbPlay, &QToolButton::clicked, this, &PlayerControls::playClicked);
    connect(ui->tbPrevMax, &QToolButton::clicked, this, [=](){prevClicked(PREV_TIME::Max);});
    connect(ui->tbPrevMid, &QToolButton::clicked, this, [=](){prevClicked(PREV_TIME::Mid);});
    connect(ui->tbPrevMin, &QToolButton::clicked, this, [=](){prevClicked(PREV_TIME::Min);});
    connect(ui->tbPrev, &QToolButton::clicked, this, [=](){playlist->previous();});

    connect(ui->tbAB,  &QToolButton::clicked, this, &PlayerControls::blockClicked);

    connect(ui->tbBlockA, &QToolButton::clicked, this, [=](){btc->showBlockTime(this, "A");});
    connect(ui->tbBlockB, &QToolButton::clicked, this, [=](){btc->showBlockTime(this, "B");});


  //  connect(playlist, SIGNAL(currentIndexChanged(int)), plv, SLOT(playlistChanged(int)));

    //음악이 바뀔때 슬라이의 최대값을 조정한다.
    connect(player, &NMediaPlayer::durationChanged, this, [=](qint64 duration){
        ui->hsPlayTime->setMaximum(duration/1000);
        ui->lbDurationEnd->setText(secondToTimeString(duration, "m:ss"));
    });

    //음악이 플레이될때 슬라이드의 위치를 옮긴다.
    connect(player, &NMediaPlayer::positionChanged, this, [=](qint64 position){
        ui->hsPlayTime->setValue(position/1000);
        ui->lbDurationPos->setText(secondToTimeString(position, "m:ss"));
        if(blockState == BlockState::D){
            if(position >= blockB)
                player->setPosition(blockA);
        }
    });

    //음악이 멈췄을때 시작버튼으로 바꾼다
    connect(player, &NMediaPlayer::stateChanged, this, [=](QMediaPlayer::State state){
        if(state == QMediaPlayer::StoppedState){
            ui->tbPlay->setIcon(QIcon::fromTheme("media-playback-start"));
        }

    });

    //PlayBack 모드 설정
    connect(ui->tbPlayBackMode, &QToolButton::clicked, this, &PlayerControls::playBackModeClicked);

}


static bool isPlaylist(const QUrl &url) // Check for ".m3u" playlists.
{
    if (!url.isLocalFile())
        return false;
    const QFileInfo fileInfo(url.toLocalFile());
    return fileInfo.exists() && !fileInfo.suffix().compare(QLatin1String("m3u"), Qt::CaseInsensitive);
}

void PlayerControls::playBackModeClicked()
{
    switch(playlist->playbackMode()){
    case QMediaPlaylist::CurrentItemOnce:
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        ui->tbPlayBackMode->setText("CL");
        break;
    case QMediaPlaylist::CurrentItemInLoop:
        playlist->setPlaybackMode(QMediaPlaylist::Sequential);
        ui->tbPlayBackMode->setText("S");
        break;
    case QMediaPlaylist::Sequential:
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        ui->tbPlayBackMode->setText("L");
        break;
    case QMediaPlaylist::Loop:
        playlist->setPlaybackMode(QMediaPlaylist::Random);
        ui->tbPlayBackMode->setText("R");
        break;
    case QMediaPlaylist::Random:
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
        ui->tbPlayBackMode->setText("CO");
        break;
    }
}

void PlayerControls::playClicked()
{

    if(player->mediaStatus() != QMediaPlayer::NoMedia) {
        switch(player->state()){
        case QMediaPlayer::StoppedState:
        case QMediaPlayer::PausedState:
            player->play();
            ui->tbPlay->setIcon(QIcon::fromTheme("media-playback-pause"));
            break;
        case QMediaPlayer::PlayingState:
            player->pause();
            ui->tbPlay->setIcon(QIcon::fromTheme("media-playback-start"));
            break;
        }
    } else {
        QMessageBox::information(this, "", "미디어를 플레이할수 없습니다.");

    }
}

void PlayerControls::prevClicked(PREV_TIME prev)
{
    double time;
    switch(prev){
    case PREV_TIME::Max:
        time = 7.5;
        break;
    case PREV_TIME::Mid:
        time = 5;
        break;
    case PREV_TIME::Min:
    default:
        time = 2.5;
        break;
    }

    player->setPosition(player->position()-time*1000);
}

void PlayerControls::blockClicked()
{
   // if(!player->isAudioAvailable() || !player->isVideoAvailable())
   //     return;
    switch(blockState){
    case BlockState::A:
        setBlockA(0);
        ui->tbAB->setArrowType(Qt::LeftArrow);
        ui->tbAB->setText("B");
        blockState = BlockState::B;
        ui->frameTimeControl->hide();
        ui->frameABControl->show();        
        break;

    case BlockState::B:
        setBlockB(0);
        ui->tbAB->setArrowType(Qt::DownArrow);
        ui->tbAB->setText("D");
        blockState = BlockState::D;
        player->setPosition(blockA);        
        break;

    case BlockState::D:
        blockState = BlockState::A;
        ui->tbAB->setArrowType(Qt::RightArrow);
        ui->tbAB->setText("A");
        ui->tbBlockA->setText("-");
        ui->tbBlockB->setText("-");
        ui->frameABControl->hide();
        ui->frameTimeControl->show();
        break;

    }
}

void PlayerControls::setBlockA(qint64 t)
{
    if(t != 0){
        if(blockA+t < blockB){
            blockA += t;
            if(blockA<0)
                blockA = 0;
        }
    }else{
        blockA = player->position();
    }
    ui->tbBlockA->setText(secondToTimeString(blockA, "mm:ss"));
}

void PlayerControls::setBlockB(qint64 t)
{
    if(t != 0){
        if(blockB+t>blockA){
            blockB += t;
            if(blockB > player->duration())
                blockB = player->duration();
        }
    }else{
        blockB = player->position();
    }
    ui->tbBlockB->setText(secondToTimeString(blockB, "mm:ss"));
}

void PlayerControls::addToPlaylist(const QList<QUrl> urls)
{
    for (auto url : urls) {
        if (url.isEmpty())
            continue;
        if (isPlaylist(url))
            playlist->load(url);
        else
            playlist->addMedia(url);
    }
    // fixed  파일이 2개 이상일 경우 플레이 안됨
    playlist->setCurrentIndex(playlist->mediaCount()-1);
}

QString PlayerControls::secondToTimeString(int t, const QString& format)
{


    return QTime(0,0,0).addSecs(t/1000).toString(format);

}


PlayerControls::~PlayerControls()
{
    delete ui;
    delete player;
    delete playlist;
    delete btc;

}

void PlayerControls::on_tbPlayList_clicked()
{
    plv->showPlayListView(playlist);
}


void PlayerControls::on_tbStart_clicked()
{
    //player->set

}
