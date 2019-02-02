#ifndef BLOCKTIMECONTROLS_H
#define BLOCKTIMECONTROLS_H

#include <QDialog>

#include "playercontrols.h"

class PlayerControls;
namespace Ui {
class BlockTimeControls;
}

class BlockTimeControls : public QDialog
{
    Q_OBJECT

public:
    explicit BlockTimeControls(QWidget *parent = 0);
    ~BlockTimeControls();

    void showBlockTime(PlayerControls* pc, QString block);
public slots:
    void setBlockTime(float t);
private:
    Ui::BlockTimeControls *ui;
    PlayerControls* pc;
    QString block;
};

#endif // BLOCKTIMECONTROLS_H
