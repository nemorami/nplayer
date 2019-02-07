#ifndef PLAYLISTVIEW_H
#define PLAYLISTVIEW_H



#include <QMediaPlaylist>
#include <QWidget>
#include "playlistmodel.h"

class PlayListModel;
namespace Ui {
class PlayListView;
}

class PlayListView : public QWidget
{
    Q_OBJECT

public:
    explicit PlayListView(QWidget *parent = nullptr, PlayListModel *plm = nullptr);
    ~PlayListView();

public slots:
    void showPlayListView();
   // void playlistChanged(int index);
private:
    Ui::PlayListView *ui; 

};

#endif // PLAYLISTVIEW_H
