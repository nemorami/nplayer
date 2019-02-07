#include "playlistview.h"
#include "ui_playlistview.h"
#include "playlistmodel.h"

PlayListView::PlayListView(QWidget *parent, PlayListModel* plm) :
    QWidget(parent),
    ui(new Ui::PlayListView)
{
    ui->setupUi(this);


//    if(playlist != nullptr){
//           _playlist = playlist;

       ///    plm->setPlaylist(playlist);
           ui->listView->setModel(plm);
           //ui->listView->setCurrentIndex(plm->index(0,0));
//       }
}

void PlayListView::showPlayListView()
{
    show();
}

//void PlayListView::playlistChanged(int index)
//{
//    ui->listView->setCurrentIndex(plm->index(index,0));
//}

PlayListView::~PlayListView()
{
    delete ui;
}
