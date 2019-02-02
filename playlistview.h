#ifndef PLAYLISTVIEW_H
#define PLAYLISTVIEW_H



#include <QMediaPlaylist>
#include <QWidget>

class PlayListModel;
namespace Ui {
class PlayListView;
}

class PlayListView : public QWidget
{
    Q_OBJECT

public:
    explicit PlayListView(QWidget *parent = 0);
    ~PlayListView();

public slots:
    void showPlayListView(QMediaPlaylist *playlist);
    void playlistChanged(int index);
private:
    Ui::PlayListView *ui;
    QMediaPlaylist* _playlist;
    PlayListModel* plm;
};

#endif // PLAYLISTVIEW_H
