#include "mimeitem.h"

#include <QtCore/QDebug>

MimeItem::MimeItem(QMimeType type)
    : mime_(type)
{
    auto list = type.name().split("/");
    list.removeFirst();
    name_ = list.join("/");
}

QString MimeItem::name() const
{
    return name_;
}

QString MimeItem::description() const
{
    return mime_.comment();
}

QString MimeItem::preferredSuffix() const
{
    return mime_.preferredSuffix();
}

QString MimeItem::suffixes() const
{
    return mime_.suffixes().join(",");
}

QString MimeItem::mimeName() const
{
    return mime_.name();
}
