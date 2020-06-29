/********************************************************************************
** Form generated from reading UI file 'playlistview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTVIEW_H
#define UI_PLAYLISTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlaylistView
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListView *listView;

    void setupUi(QWidget *PlaylistView)
    {
        if (PlaylistView->objectName().isEmpty())
            PlaylistView->setObjectName(QString::fromUtf8("PlaylistView"));
        PlaylistView->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(PlaylistView);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listView = new QListView(PlaylistView);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(PlaylistView);

        QMetaObject::connectSlotsByName(PlaylistView);
    } // setupUi

    void retranslateUi(QWidget *PlaylistView)
    {
        PlaylistView->setWindowTitle(QCoreApplication::translate("PlaylistView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlaylistView: public Ui_PlaylistView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTVIEW_H
