#include "playlistmodel.h"

#include <QFileInfo>

PlayListModel::PlayListModel(QObject *parent)
    :QAbstractItemModel (parent), _playlist(0)
{

}

void PlayListModel::setPlaylist(QMediaPlaylist *playlist)
{
    if (_playlist) {
          disconnect(_playlist, SIGNAL(mediaAboutToBeInserted(int,int)), this, SLOT(beginInsertItems(int,int)));
          disconnect(_playlist, SIGNAL(mediaInserted(int,int)), this, SLOT(endInsertItems()));
          disconnect(_playlist, SIGNAL(mediaAboutToBeRemoved(int,int)), this, SLOT(beginRemoveItems(int,int)));
          disconnect(_playlist, SIGNAL(mediaRemoved(int,int)), this, SLOT(endRemoveItems()));
          disconnect(_playlist, SIGNAL(mediaChanged(int,int)), this, SLOT(changeItems(int,int)));
      }

      beginResetModel();
      _playlist = playlist;

      if (_playlist) {
          connect(_playlist, SIGNAL(mediaAboutToBeInserted(int,int)), this, SLOT(beginInsertItems(int,int)));
          connect(_playlist, SIGNAL(mediaInserted(int,int)), this, SLOT(endInsertItems()));
          connect(_playlist, SIGNAL(mediaAboutToBeRemoved(int,int)), this, SLOT(beginRemoveItems(int,int)));
          connect(_playlist, SIGNAL(mediaRemoved(int,int)), this, SLOT(endRemoveItems()));
          connect(_playlist, SIGNAL(mediaChanged(int,int)), this, SLOT(changeItems(int,int)));
      }

      endResetModel();
}

QMediaPlaylist *PlayListModel::playlist() const
{
    return _playlist;
}

bool PlayListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
//    Q_UNUSED(role);
//    _data[index] = value;
//    emit dataChanged(index, index);
    return true;
}

int PlayListModel::rowCount(const QModelIndex &parent) const
{
    return _playlist && !parent.isValid() ? _playlist->mediaCount() : 0;
}

int PlayListModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? ColumnCount : 0;
}

QModelIndex PlayListModel::index(int row, int column, const QModelIndex &parent) const
{
    return _playlist && !parent.isValid()
            && row >= 0 && row < _playlist->mediaCount()
            && column >= 0 && column < ColumnCount
        ? createIndex(row, column)
        : QModelIndex();
}

QModelIndex PlayListModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);

    return QModelIndex();
}

QVariant PlayListModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && role == Qt::DisplayRole) {
        QVariant value = _data[index];
        if (!value.isValid() && index.column() == Title) {
            QUrl location = _playlist->media(index.row()).canonicalUrl();
            return QFileInfo(location.path()).fileName();
        }

        return value;
    }
    return QVariant();
}


void PlayListModel::beginInsertItems(int start, int end)
{
    _data.clear();
    beginInsertRows(QModelIndex(), start, end);
}

void PlayListModel::endInsertItems()
{
    endInsertRows();
}

void PlayListModel::beginRemoveItems(int start, int end)
{
    _data.clear();
    beginRemoveRows(QModelIndex(), start, end);
}

void PlayListModel::endRemoveItems()
{
    endInsertRows();
}

void PlayListModel::changeItems(int start, int end)
{
    _data.clear();
    emit dataChanged(index(start,0), index(end,ColumnCount));
}
