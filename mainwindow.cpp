#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <QMimeData>
#include <QMessageBox>
#include <QDockWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    playlist = new  QMediaPlaylist();
    pc = new PlayerControls(playlist, this);
    setCentralWidget(pc);
    connect(ui->action_Open, &QAction::triggered, this, &MainWindow::open);
    ui->mainToolBar->addAction(ui->action_Open);
    // Drop 기능 활성화
    setAcceptDrops(true);
    // TODO dock 설정파일
    pl = new QDockWidget(this);
    pl->setAllowedAreas(Qt::RightDockWidgetArea);
    plv = new PlaylistView(playlist, parent);
    pl->setWidget(plv);
    connect(playlist, &QMediaPlaylist::currentIndexChanged, plv, &PlaylistView::setHighlight);
    addDockWidget(Qt::RightDockWidgetArea, pl);


}


void MainWindow::open()
{
    if(qApp->arguments().size()>1){
        QList<QUrl> list = QUrl::fromStringList(qApp->arguments());
        addToPlaylist(list);
    }else{
        QFileDialog fileDialog(this);
        fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
        fileDialog.setFileMode(QFileDialog::ExistingFiles); //여러파일 선택
        fileDialog.setWindowTitle(tr("Open Files"));
        /*
    QStringList supportedMimeTypes = pc->supportedMimeTypes();
    if (!supportedMimeTypes.isEmpty()) {
        supportedMimeTypes.append("audio/x-m3u"); // MP3 playlists
        fileDialog.setMimeTypeFilters(supportedMimeTypes);
    }
    */
        fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(0, QDir::homePath()));
        if (fileDialog.exec() == QDialog::Accepted)
            addToPlaylist(fileDialog.selectedUrls());
    }
}

void MainWindow::togglePlaylistView()
{
    pl->setVisible(!pl->isVisible());
}

static bool isPlaylist(const QUrl &url) // Check for ".m3u" playlists.
{
    if (!url.isLocalFile())
        return false;
    const QFileInfo fileInfo(url.toLocalFile());
    return fileInfo.exists() && !fileInfo.suffix().compare(QLatin1String("m3u"), Qt::CaseInsensitive);
}

void MainWindow::addToPlaylist(const QList<QUrl> urls)
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
    plv->setHighlight(playlist->mediaCount()-1);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete pc;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("text/plain"))
        event->acceptProposedAction();
}


void MainWindow::dropEvent(QDropEvent *event)
{
   // addToPlaylist(QUrl::fromStringList(event->mimeData()->text().split("\n")));

    QMessageBox::information(this, "title", event->mimeData()->text());
    event->acceptProposedAction();
}
