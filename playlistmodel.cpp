
#include "playlistmodel.h"

#include <QFileInfo>
#include <QUrl>
#include "qmediaplaylist.h"


PlaylistModel::PlaylistModel(QObject *parent)
    : QAbstractItemModel(parent)
{
}

PlaylistModel::~PlaylistModel()
{
}

int PlaylistModel::rowCount(const QModelIndex &parent) const
{
    return m_playlist && !parent.isValid() ? m_playlist->mediaCount() : 0;
}

int PlaylistModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? ColumnCount : 0;
}

QModelIndex PlaylistModel::index(int row, int column, const QModelIndex &parent) const
{
    return m_playlist && !parent.isValid()
            && row >= 0 && row < m_playlist->mediaCount()
            && column >= 0 && column < ColumnCount
        ? createIndex(row, column)
        : QModelIndex();
}

QModelIndex PlaylistModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);

    return QModelIndex();
}

QVariant PlaylistModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && role == Qt::DisplayRole) {
        QVariant value = m_data[index];
        if (!value.isValid() && index.column() == Title) {
            QUrl location = m_playlist->media(index.row()).request().url();
            return QFileInfo(location.path()).fileName();
        }

        return value;
    }
    return QVariant();
}

QMediaPlaylist *PlaylistModel::playlist() const
{
    return m_playlist.data();
}

void PlaylistModel::setPlaylist(QMediaPlaylist *playlist)
{
    if (m_playlist) {
        disconnect(m_playlist.data(), &QMediaPlaylist::mediaAboutToBeInserted, this, &PlaylistModel::beginInsertItems);
        disconnect(m_playlist.data(), &QMediaPlaylist::mediaInserted, this, &PlaylistModel::endInsertItems);
        disconnect(m_playlist.data(), &QMediaPlaylist::mediaAboutToBeRemoved, this, &PlaylistModel::beginRemoveItems);
        disconnect(m_playlist.data(), &QMediaPlaylist::mediaRemoved, this, &PlaylistModel::endRemoveItems);
        disconnect(m_playlist.data(), &QMediaPlaylist::mediaChanged, this, &PlaylistModel::changeItems);
    }

    beginResetModel();
    m_playlist.reset(playlist);

    if (m_playlist) {
        connect(m_playlist.data(), &QMediaPlaylist::mediaAboutToBeInserted, this, &PlaylistModel::beginInsertItems);
        connect(m_playlist.data(), &QMediaPlaylist::mediaInserted, this, &PlaylistModel::endInsertItems);
        connect(m_playlist.data(), &QMediaPlaylist::mediaAboutToBeRemoved, this, &PlaylistModel::beginRemoveItems);
        connect(m_playlist.data(), &QMediaPlaylist::mediaRemoved, this, &PlaylistModel::endRemoveItems);
        connect(m_playlist.data(), &QMediaPlaylist::mediaChanged, this, &PlaylistModel::changeItems);
    }

    endResetModel();
}

bool PlaylistModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(role);
    m_data[index] = value;
    emit dataChanged(index, index);
    return true;
}

void PlaylistModel::beginInsertItems(int start, int end)
{
    m_data.clear();
    beginInsertRows(QModelIndex(), start, end);
}

void PlaylistModel::endInsertItems()
{
    endInsertRows();
}

void PlaylistModel::beginRemoveItems(int start, int end)
{
    m_data.clear();
    beginRemoveRows(QModelIndex(), start, end);
}

void PlaylistModel::endRemoveItems()
{    endRemoveRows();
}

void PlaylistModel::changeItems(int start, int end)
{
    m_data.clear();
    emit dataChanged(index(start,0), index(end,ColumnCount));
}

bool PlaylistModel::removeRow(int row){

    if(0 > row || (row + 1) > rowCount())
        return false;
    m_playlist->removeMedia(row);
    return true;
}
