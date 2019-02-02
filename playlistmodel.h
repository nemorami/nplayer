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
    PlayListModel(QObject *parent =0);
    void setPlaylist(QMediaPlaylist *playlist);
    QMediaPlaylist *playlist() const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

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
