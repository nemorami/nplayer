#ifndef PLAYLISTVIEW_H
#define PLAYLISTVIEW_H



#include <QMediaPlaylist>
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
};

#endif // PLAYLISTVIEW_H
