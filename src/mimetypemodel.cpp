#include "mimetypemodel.h"

MimetypeModel::MimetypeModel(QObject *parent)
    : QAbstractListModel(parent)
{
    roles_[NameRole] = "name";
    roles_[DescriptionRole] = "description";
    roles_[PreferedSuffixRole] = "preferredSuffix";
    roles_[SuffixesRole] = "suffixes";
    roles_[MimeNameRole] = "mimeName";
}

int MimetypeModel::rowCount(const QModelIndex &) const
{
    return data_.size();
}

QVariant MimetypeModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if (row < 0 || row > data_.size()) return QVariant();
    auto item = data_.at(row);
    switch (role)
    {
    case NameRole: return item.name();
    case DescriptionRole: return item.description();
    case PreferedSuffixRole: return item.preferredSuffix();
    case SuffixesRole: return item.suffixes();
    case MimeNameRole: return item.mimeName();
    default: return QVariant();
    }
}

QHash<int, QByteArray> MimetypeModel::roleNames() const
{
    return roles_;
}

void MimetypeModel::appendRow(MimeItem item)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    data_.append(item);
    endInsertRows();
}

