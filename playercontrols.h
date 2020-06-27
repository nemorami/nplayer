#ifndef PLAYERCONTROLS_H
#define PLAYERCONTROLS_H

#include <QWidget>
#include "nmediaplayer.h"


#include "blocktimecontrols.h"
#include "playlistview.h"
class BlockTimeControls;
namespace Ui {
class PlayerControls;

}

class PlayerControls : public QWidget
{
    Q_OBJECT

public:
    PlayerControls( QMediaPlaylist *playlist, QWidget *parent = nullptr);
    ~PlayerControls();


    enum class PREV_TIME {Min, Mid, Max};
    enum class BlockState { A, B, D};
    BlockState blockState;
    QString secondToTimeString(int t, const QString &format);

    void setBlockA(float t);
    void setBlockB(float t);

    void previous();
public slots:
    void playClicked();
    void prevClicked(PREV_TIME prev);
    void blockClicked();
    void playBackModeClicked();
    void next();

private:
    Ui::PlayerControls *ui;
    NMediaPlayer* player;

    BlockTimeControls* btc;

    qint64 blockA;
    qint64 blockB;
};

#endif // PLAYERCONTROLS_H
