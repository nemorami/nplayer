#include "playlistview.h"
#include "ui_playlistview.h"
#include "playlistmodel.h"

#include <QMenu>

PlaylistView::PlaylistView(QMediaPlaylist *playlist, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistView)
{
    ui->setupUi(this);
    plm = new PlaylistModel(this);
    plm->setPlaylist(playlist);
    ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->listView->verticalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->listView->setModel(plm);
    ui->listView->setCurrentIndex(plm->index(plm->playlist()->currentIndex(),0));

    // TooBar
    toolbar = new QToolBar("", this);

    // context menu
    connect(ui->listView, &QTableView::customContextMenuRequested, this, &PlaylistView::contextMenu);
    connect(ui->listView->verticalHeader(), &QHeaderView::customContextMenuRequested, this, &PlaylistView::contextMenu);

}

void PlaylistView::setHighlight(int index)
{
    ui->listView->setCurrentIndex(plm->index(index,0));
}

void PlaylistView::contextMenu(QPoint point)
{
    QMenu *menu=new QMenu(this);
    menu->addAction("delete", this, &PlaylistView::deleteItem);
    menu->addAction(new QAction("Action 2", this));
    menu->addAction(new QAction("Action 3", this));
    //FIXME 헤더에서 마우스를 클릭했을때 테이블 뷰 영역에서 메뉴를 보여줌.
    menu->popup(ui->listView->viewport()->mapToGlobal(point));
}

void PlaylistView::deleteItem()
{
    for (auto row : ui->listView->selectionModel()->selectedRows()) {
        qDebug() << row.row();
        plm->removeRow(row.row());
    }
    plm->submit();
}

PlaylistView::~PlaylistView()
{
    delete ui;
}
