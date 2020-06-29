/********************************************************************************
** Form generated from reading UI file 'playercontrols.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERCONTROLS_H
#define UI_PLAYERCONTROLS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerControls
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbDurationPos;
    QSlider *hsPlayTime;
    QLabel *lbDurationEnd;
    QFrame *frameMain;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *lyFrameMain;
    QToolButton *tbStart;
    QToolButton *tbPrevious;
    QToolButton *tbPlay;
    QToolButton *tbNext;
    QToolButton *tbEnd;
    QToolButton *tbAB;
    QToolButton *tbPlayList;
    QToolButton *tbPlayBackMode;
    QSpacerItem *horizontalSpacer_6;
    QFrame *frameTimeControl;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *lyTimeControl;
    QToolButton *tbPrevMax;
    QToolButton *tbPrevMid;
    QToolButton *tbPrevMin;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frameABControl;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *lyABControl;
    QToolButton *tbBlockA;
    QToolButton *tbBlockB;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *PlayerControls)
    {
        if (PlayerControls->objectName().isEmpty())
            PlayerControls->setObjectName(QString::fromUtf8("PlayerControls"));
        PlayerControls->resize(550, 410);
        verticalLayoutWidget = new QWidget(PlayerControls);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(90, 20, 381, 241));
        mainLayout = new QVBoxLayout(verticalLayoutWidget);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lbDurationPos = new QLabel(verticalLayoutWidget);
        lbDurationPos->setObjectName(QString::fromUtf8("lbDurationPos"));

        horizontalLayout_4->addWidget(lbDurationPos);

        hsPlayTime = new QSlider(verticalLayoutWidget);
        hsPlayTime->setObjectName(QString::fromUtf8("hsPlayTime"));
        hsPlayTime->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(hsPlayTime);

        lbDurationEnd = new QLabel(verticalLayoutWidget);
        lbDurationEnd->setObjectName(QString::fromUtf8("lbDurationEnd"));

        horizontalLayout_4->addWidget(lbDurationEnd);


        mainLayout->addLayout(horizontalLayout_4);

        frameMain = new QFrame(verticalLayoutWidget);
        frameMain->setObjectName(QString::fromUtf8("frameMain"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameMain->sizePolicy().hasHeightForWidth());
        frameMain->setSizePolicy(sizePolicy);
        frameMain->setFrameShape(QFrame::StyledPanel);
        frameMain->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frameMain);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 0, 332, 41));
        lyFrameMain = new QHBoxLayout(horizontalLayoutWidget);
        lyFrameMain->setObjectName(QString::fromUtf8("lyFrameMain"));
        lyFrameMain->setContentsMargins(0, 0, 0, 0);
        tbStart = new QToolButton(horizontalLayoutWidget);
        tbStart->setObjectName(QString::fromUtf8("tbStart"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("media-skip-backward");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        tbStart->setIcon(icon);

        lyFrameMain->addWidget(tbStart);

        tbPrevious = new QToolButton(horizontalLayoutWidget);
        tbPrevious->setObjectName(QString::fromUtf8("tbPrevious"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("media-seek-backward");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        tbPrevious->setIcon(icon1);

        lyFrameMain->addWidget(tbPrevious);

        tbPlay = new QToolButton(horizontalLayoutWidget);
        tbPlay->setObjectName(QString::fromUtf8("tbPlay"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("media-playback-start");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        tbPlay->setIcon(icon2);
        tbPlay->setCheckable(false);

        lyFrameMain->addWidget(tbPlay);

        tbNext = new QToolButton(horizontalLayoutWidget);
        tbNext->setObjectName(QString::fromUtf8("tbNext"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("media-seek-forward");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        tbNext->setIcon(icon3);

        lyFrameMain->addWidget(tbNext);

        tbEnd = new QToolButton(horizontalLayoutWidget);
        tbEnd->setObjectName(QString::fromUtf8("tbEnd"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("media-skip-forward");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        tbEnd->setIcon(icon4);

        lyFrameMain->addWidget(tbEnd);

        tbAB = new QToolButton(horizontalLayoutWidget);
        tbAB->setObjectName(QString::fromUtf8("tbAB"));
        tbAB->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tbAB->setArrowType(Qt::RightArrow);

        lyFrameMain->addWidget(tbAB);

        tbPlayList = new QToolButton(horizontalLayoutWidget);
        tbPlayList->setObjectName(QString::fromUtf8("tbPlayList"));

        lyFrameMain->addWidget(tbPlayList);

        tbPlayBackMode = new QToolButton(horizontalLayoutWidget);
        tbPlayBackMode->setObjectName(QString::fromUtf8("tbPlayBackMode"));
        tbPlayBackMode->setToolTipDuration(-1);

        lyFrameMain->addWidget(tbPlayBackMode);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lyFrameMain->addItem(horizontalSpacer_6);


        mainLayout->addWidget(frameMain);

        frameTimeControl = new QFrame(verticalLayoutWidget);
        frameTimeControl->setObjectName(QString::fromUtf8("frameTimeControl"));
        sizePolicy.setHeightForWidth(frameTimeControl->sizePolicy().hasHeightForWidth());
        frameTimeControl->setSizePolicy(sizePolicy);
        frameTimeControl->setFrameShape(QFrame::StyledPanel);
        frameTimeControl->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget_2 = new QWidget(frameTimeControl);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 241, 71));
        lyTimeControl = new QHBoxLayout(horizontalLayoutWidget_2);
        lyTimeControl->setObjectName(QString::fromUtf8("lyTimeControl"));
        lyTimeControl->setContentsMargins(0, 0, 0, 0);
        tbPrevMax = new QToolButton(horizontalLayoutWidget_2);
        tbPrevMax->setObjectName(QString::fromUtf8("tbPrevMax"));
        tbPrevMax->setAutoFillBackground(false);
        tbPrevMax->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tbPrevMax->setArrowType(Qt::LeftArrow);

        lyTimeControl->addWidget(tbPrevMax);

        tbPrevMid = new QToolButton(horizontalLayoutWidget_2);
        tbPrevMid->setObjectName(QString::fromUtf8("tbPrevMid"));
        tbPrevMid->setAutoFillBackground(false);
        tbPrevMid->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tbPrevMid->setArrowType(Qt::LeftArrow);

        lyTimeControl->addWidget(tbPrevMid);

        tbPrevMin = new QToolButton(horizontalLayoutWidget_2);
        tbPrevMin->setObjectName(QString::fromUtf8("tbPrevMin"));
        tbPrevMin->setAutoFillBackground(false);
        tbPrevMin->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tbPrevMin->setArrowType(Qt::LeftArrow);

        lyTimeControl->addWidget(tbPrevMin);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lyTimeControl->addItem(horizontalSpacer_2);


        mainLayout->addWidget(frameTimeControl);

        frameABControl = new QFrame(verticalLayoutWidget);
        frameABControl->setObjectName(QString::fromUtf8("frameABControl"));
        sizePolicy.setHeightForWidth(frameABControl->sizePolicy().hasHeightForWidth());
        frameABControl->setSizePolicy(sizePolicy);
        frameABControl->setFrameShape(QFrame::StyledPanel);
        frameABControl->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget_3 = new QWidget(frameABControl);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(40, 0, 160, 80));
        lyABControl = new QHBoxLayout(horizontalLayoutWidget_3);
        lyABControl->setObjectName(QString::fromUtf8("lyABControl"));
        lyABControl->setContentsMargins(0, 0, 0, 0);
        tbBlockA = new QToolButton(horizontalLayoutWidget_3);
        tbBlockA->setObjectName(QString::fromUtf8("tbBlockA"));
        tbBlockA->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tbBlockA->setArrowType(Qt::DownArrow);

        lyABControl->addWidget(tbBlockA);

        tbBlockB = new QToolButton(horizontalLayoutWidget_3);
        tbBlockB->setObjectName(QString::fromUtf8("tbBlockB"));
        tbBlockB->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tbBlockB->setArrowType(Qt::DownArrow);

        lyABControl->addWidget(tbBlockB);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lyABControl->addItem(horizontalSpacer_4);


        mainLayout->addWidget(frameABControl);


        retranslateUi(PlayerControls);

        QMetaObject::connectSlotsByName(PlayerControls);
    } // setupUi

    void retranslateUi(QWidget *PlayerControls)
    {
        PlayerControls->setWindowTitle(QCoreApplication::translate("PlayerControls", "Form", nullptr));
        lbDurationPos->setText(QCoreApplication::translate("PlayerControls", "0", nullptr));
        lbDurationEnd->setText(QCoreApplication::translate("PlayerControls", "0", nullptr));
        tbStart->setText(QCoreApplication::translate("PlayerControls", "...", nullptr));
        tbPrevious->setText(QCoreApplication::translate("PlayerControls", "...", nullptr));
        tbPlay->setText(QCoreApplication::translate("PlayerControls", "...", nullptr));
        tbNext->setText(QCoreApplication::translate("PlayerControls", "...", nullptr));
        tbEnd->setText(QCoreApplication::translate("PlayerControls", "...", nullptr));
        tbAB->setText(QCoreApplication::translate("PlayerControls", "A", nullptr));
        tbPlayList->setText(QCoreApplication::translate("PlayerControls", "PL", nullptr));
#if QT_CONFIG(tooltip)
        tbPlayBackMode->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        tbPlayBackMode->setText(QCoreApplication::translate("PlayerControls", "S", nullptr));
        tbPrevMax->setText(QCoreApplication::translate("PlayerControls", "7.5", nullptr));
        tbPrevMid->setText(QCoreApplication::translate("PlayerControls", "5.0", nullptr));
        tbPrevMin->setText(QCoreApplication::translate("PlayerControls", "2.5", nullptr));
        tbBlockA->setText(QCoreApplication::translate("PlayerControls", "0.00", nullptr));
        tbBlockB->setText(QCoreApplication::translate("PlayerControls", "0.00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerControls: public Ui_PlayerControls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERCONTROLS_H
