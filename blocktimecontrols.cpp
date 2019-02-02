#include "blocktimecontrols.h"
#include "ui_blocktimecontrols.h"

BlockTimeControls::BlockTimeControls(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BlockTimeControls)
{
    ui->setupUi(this);
    setLayout(ui->mainLayout);
    connect(ui->tb_2s, &QToolButton::clicked, this, [=](){setBlockTime(-2);});
    connect(ui->tb_1s, &QToolButton::clicked, this, [=](){setBlockTime(-1);});
    connect(ui->tb_0_5s, &QToolButton::clicked, this, [=](){setBlockTime(-0.5);});
    connect(ui->tb_0_1s, &QToolButton::clicked, this, [=](){setBlockTime(-0.1);});

    connect(ui->tb2s, &QToolButton::clicked, this, [=](){setBlockTime(2);});
    connect(ui->tb1s, &QToolButton::clicked, this, [=](){setBlockTime(1);});
    connect(ui->tb0_5s, &QToolButton::clicked, this, [=](){setBlockTime(0.5);});
    connect(ui->tb0_1s, &QToolButton::clicked, this, [=](){setBlockTime(0.1);});

}

void BlockTimeControls::showBlockTime(PlayerControls* pc, QString block)
{
    this->pc = pc;
    this->block = block;
    show();
}

void BlockTimeControls::setBlockTime(float t)
{
    if(block =="A"){
        pc->setBlockA(t*1000);
    }else {
        pc->setBlockB(t*1000);
    }
}

BlockTimeControls::~BlockTimeControls()
{
    delete ui;
}
