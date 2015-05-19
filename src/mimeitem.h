#ifndef MIMEITEM_H
#define MIMEITEM_H

#include <QtCore/QString>
#include <QtCore/QMimeType>

class MimeItem
{
public:
    explicit MimeItem(QMimeType type);

    QString name() const;
    QString description() const;
    QString preferredSuffix() const;
    QString suffixes() const;
    QString mimeName() const;

private:
    QMimeType mime_;
    QString name_;
};

#endif // MIMEITEM_H
