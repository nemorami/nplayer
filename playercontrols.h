#ifndef PLAYERCONTROLS_H
#define PLAYERCONTROLS_H

#include <QFileInfo>
#include <QTime>
#include <QMessageBox>
#include <QWidget>
#include "nmediaplayer.h"
#include <QMediaPlaylist>

//#include "blocktimecontrols.h"
#include "playlistview.h"
class BlockTimeControls;
namespace Ui {
class PlayerControls;

}

class PlayerControls : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerControls(QWidget *parent = nullptr);
    ~PlayerControls();

    void addToPlaylist(const QList<QUrl> urls);
    enum class PREV_TIME {Min, Mid, Max};
    enum class BlockState { A, B, D};
    BlockState blockState;
    QString secondToTimeString(int t, const QString &format);

    void setBlockA(qint64 t);
    void setBlockB(qint64 t);
public slots:
    void playClicked();
    void prevClicked(PREV_TIME prev);
    void blockClicked();
    void playBackModeClicked();
private slots:
    void on_tbPlayList_clicked();
    void on_tbStart_clicked();
    void on_hsPlayTime_sliderMoved(int value);

private:
    Ui::PlayerControls *ui; 
    QMediaPlaylist *playlist;
    NMediaPlayer* player;

    PlayListView* plv;
    BlockTimeControls* btc;

    qint64 blockA;
    qint64 blockB;
};
#endif // PLAYERCONTROLS_H
