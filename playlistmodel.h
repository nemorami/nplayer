#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QMediaPlaylist>
#include <QModelIndex>



class PlayListModel : public QAbstractItemModel
{
public:
    enum Column
    {
        Title = 0,
        ColumnCount
    };
    PlayListModel(QObject *parent =nullptr, QMediaPlaylist *playlist = nullptr);
    //void setPlaylist(QMediaPlaylist *playlist);
   // QMediaPlaylist *playlist() const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    void dataChange(int row);


private slots:
    void beginInsertItems(int start, int end);
    void endInsertItems();
    void beginRemoveItems(int start, int end);
    void endRemoveItems();
    void changeItems(int start, int end);
private:
    QMediaPlaylist* _playlist;
    QMap<QModelIndex, QVariant> _data;
};

#endif // PLAYLISTMODEL_H
