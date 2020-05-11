#include "playlistview.h"
#include "ui_playlistview.h"
#include "playlistmodel.h"

PlaylistView::PlaylistView(QMediaPlaylist *playlist, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistView)
{
    ui->setupUi(this);
    plm = new PlaylistModel(this);
    plm->setPlaylist(playlist);
    ui->listView->setModel(plm);
    ui->listView->setCurrentIndex(plm->index(plm->playlist()->currentIndex(),0));




}

void PlaylistView::setHighlight(int index)
{
    ui->listView->setCurrentIndex(plm->index(index,0));
}

PlaylistView::~PlaylistView()
{
    delete ui;
}
