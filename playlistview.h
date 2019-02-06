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
    explicit PlayListView(QWidget *parent = nullptr, QMediaPlaylist *playlist = nullptr);
    ~PlayListView();

public slots:
    void showPlayListView();
    void playlistChanged(int index);
private:
    Ui::PlayListView *ui; 
    PlayListModel* plm;
};

#endif // PLAYLISTVIEW_H
