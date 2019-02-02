#include "playlistview.h"
#include "ui_playlistview.h"
#include "playlistmodel.h"

PlayListView::PlayListView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayListView)
{
    ui->setupUi(this);
    plm = new PlayListModel(this);

}

void PlayListView::showPlayListView(QMediaPlaylist* playlist)
{
    if(playlist != nullptr){
        _playlist = playlist;

        plm->setPlaylist(_playlist);
        ui->listView->setModel(plm);
        ui->listView->setCurrentIndex(plm->index(_playlist->currentIndex(),0));
    }
    show();
}

void PlayListView::playlistChanged(int index)
{
    ui->listView->setCurrentIndex(plm->index(index,0));
}

PlayListView::~PlayListView()
{
    delete ui;
}
