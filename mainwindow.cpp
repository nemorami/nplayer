#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <QMimeData>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pc = new PlayerControls(this);
    setCentralWidget(pc);
    connect(ui->action_Open, &QAction::triggered, this, &MainWindow::open);
    ui->mainToolBar->addAction(ui->action_Open);
    // Drop 기능 활성화
    setAcceptDrops(true);

}


void MainWindow::open()
{
    if(qApp->arguments().size()>1){
        QList<QUrl> list = QUrl::fromStringList(qApp->arguments());
        pc->addToPlaylist(list);
    }else{
        QFileDialog fileDialog(this);
        fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
        fileDialog.setWindowTitle(tr("Open Files"));
        /*
    QStringList supportedMimeTypes = pc->supportedMimeTypes();
    if (!supportedMimeTypes.isEmpty()) {
        supportedMimeTypes.append("audio/x-m3u"); // MP3 playlists
        fileDialog.setMimeTypeFilters(supportedMimeTypes);
    }
    */
        fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(0, QDir::homePath()));
        if (fileDialog.exec() == QDialog::Accepted)
            pc->addToPlaylist(fileDialog.selectedUrls());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pc;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("text/plain"))
        event->acceptProposedAction();
}


void MainWindow::dropEvent(QDropEvent *event)
{
    pc->addToPlaylist(QUrl::fromStringList(event->mimeData()->text().split("\n")));
    //event->mimeData()->text() 테스트를 위한코드
    //QMessageBox::information(this, "", event->mimeData()->text());
    event->acceptProposedAction();
}
