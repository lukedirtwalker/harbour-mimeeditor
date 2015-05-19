#ifndef MIMETYPEMODEL_H
#define MIMETYPEMODEL_H

#include <QtCore/QAbstractListModel>

#include "mimeitem.h"

class MimetypeModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        DescriptionRole = Qt::UserRole + 2,
        PreferedSuffixRole = Qt::UserRole + 3,
        SuffixesRole = Qt::UserRole + 4,
        MimeNameRole = Qt::UserRole + 5,
    };

    explicit MimetypeModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

    void appendRow(MimeItem item);


private:
    QList<MimeItem> data_;
    QHash<int, QByteArray> roles_;
};

#endif // MIMETYPEMODEL_H
