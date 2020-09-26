#ifndef PLAYLISTVIEW_H
#define PLAYLISTVIEW_H



#include <QMediaPlaylist>
#include <QToolBar>
#include <QWidget>

class PlaylistModel;

namespace Ui {
class PlaylistView;
}

class PlaylistView : public QWidget
{
    Q_OBJECT

public:
    explicit PlaylistView(QMediaPlaylist *playlist, QWidget *parent = 0);
    ~PlaylistView();

public slots:  
    void setHighlight(int index);
private:
    Ui::PlaylistView *ui;
    PlaylistModel* plm;
    QToolBar *toolbar;
};

#endif // PLAYLISTVIEW_H
