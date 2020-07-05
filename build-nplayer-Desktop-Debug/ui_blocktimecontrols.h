/********************************************************************************
** Form generated from reading UI file 'blocktimecontrols.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCKTIMECONTROLS_H
#define UI_BLOCKTIMECONTROLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlockTimeControls
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *tb_2s;
    QToolButton *tb_1s;
    QToolButton *tb_0_5s;
    QToolButton *tb_0_1s;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *tb0_1s;
    QToolButton *tb0_5s;
    QToolButton *tb1s;
    QToolButton *tb2s;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QDialog *BlockTimeControls)
    {
        if (BlockTimeControls->objectName().isEmpty())
            BlockTimeControls->setObjectName(QString::fromUtf8("BlockTimeControls"));
        BlockTimeControls->resize(400, 300);
        verticalLayoutWidget = new QWidget(BlockTimeControls);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 20, 326, 166));
        mainLayout = new QVBoxLayout(verticalLayoutWidget);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tb_2s = new QToolButton(verticalLayoutWidget);
        tb_2s->setObjectName(QString::fromUtf8("tb_2s"));
        tb_2s->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tb_2s->setArrowType(Qt::LeftArrow);

        horizontalLayout->addWidget(tb_2s);

        tb_1s = new QToolButton(verticalLayoutWidget);
        tb_1s->setObjectName(QString::fromUtf8("tb_1s"));
        tb_1s->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tb_1s->setArrowType(Qt::LeftArrow);

        horizontalLayout->addWidget(tb_1s);

        tb_0_5s = new QToolButton(verticalLayoutWidget);
        tb_0_5s->setObjectName(QString::fromUtf8("tb_0_5s"));
        tb_0_5s->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tb_0_5s->setArrowType(Qt::LeftArrow);

        horizontalLayout->addWidget(tb_0_5s);

        tb_0_1s = new QToolButton(verticalLayoutWidget);
        tb_0_1s->setObjectName(QString::fromUtf8("tb_0_1s"));
        tb_0_1s->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tb_0_1s->setArrowType(Qt::LeftArrow);

        horizontalLayout->addWidget(tb_0_1s);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        mainLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        tb0_1s = new QToolButton(verticalLayoutWidget);
        tb0_1s->setObjectName(QString::fromUtf8("tb0_1s"));
        tb0_1s->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tb0_1s->setArrowType(Qt::RightArrow);

        horizontalLayout_2->addWidget(tb0_1s);

        tb0_5s = new QToolButton(verticalLayoutWidget);
        tb0_5s->setObjectName(QString::fromUtf8("tb0_5s"));
        tb0_5s->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tb0_5s->setArrowType(Qt::RightArrow);

        horizontalLayout_2->addWidget(tb0_5s);

        tb1s = new QToolButton(verticalLayoutWidget);
        tb1s->setObjectName(QString::fromUtf8("tb1s"));
        tb1s->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tb1s->setArrowType(Qt::RightArrow);

        horizontalLayout_2->addWidget(tb1s);

        tb2s = new QToolButton(verticalLayoutWidget);
        tb2s->setObjectName(QString::fromUtf8("tb2s"));
        tb2s->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tb2s->setArrowType(Qt::RightArrow);

        horizontalLayout_2->addWidget(tb2s);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        mainLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        mainLayout->addLayout(horizontalLayout_3);


        retranslateUi(BlockTimeControls);
        QObject::connect(buttonBox, SIGNAL(accepted()), BlockTimeControls, SLOT(accept()));

        QMetaObject::connectSlotsByName(BlockTimeControls);
    } // setupUi

    void retranslateUi(QDialog *BlockTimeControls)
    {
        BlockTimeControls->setWindowTitle(QCoreApplication::translate("BlockTimeControls", "Dialog", nullptr));
        tb_2s->setText(QCoreApplication::translate("BlockTimeControls", "2", nullptr));
        tb_1s->setText(QCoreApplication::translate("BlockTimeControls", "1", nullptr));
        tb_0_5s->setText(QCoreApplication::translate("BlockTimeControls", "0.5", nullptr));
        tb_0_1s->setText(QCoreApplication::translate("BlockTimeControls", "0.1", nullptr));
        tb0_1s->setText(QCoreApplication::translate("BlockTimeControls", "0.1", nullptr));
        tb0_5s->setText(QCoreApplication::translate("BlockTimeControls", "0.5", nullptr));
        tb1s->setText(QCoreApplication::translate("BlockTimeControls", "1", nullptr));
        tb2s->setText(QCoreApplication::translate("BlockTimeControls", "2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BlockTimeControls: public Ui_BlockTimeControls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKTIMECONTROLS_H
