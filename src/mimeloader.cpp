#include "mimeloader.h"

#include <QtCore/QDebug>

#include <contentaction.h>

#include "mimeitem.h"

MimeLoader::MimeLoader()
{
    for (auto mimetype : db_.allMimeTypes())
    {
        QString key = mimetype.name();
        key = key.split("/").front();
        auto it = models_.find(key);
        if (it != models_.end())
        {
            it.value()->appendRow(MimeItem(mimetype));
        }
        else
        {
            auto model = new MimetypeModel(this);
            model->appendRow(MimeItem(mimetype));
            models_[key] = model;
        }
    }
}

QStringList MimeLoader::categories() const
{
    return models_.keys();
}

MimetypeModel *MimeLoader::modelForCategory(const QString &category) const
{
    return models_[category];
}

bool MimeLoader::hasDefaultApp(const QString &mimeType) const
{
    return !ContentAction::actionsForMime(mimeType).empty();
}

QString MimeLoader::defaultAppName(const QString &mimeType) const
{
    auto actions = ContentAction::actionsForMime(mimeType);
    if (actions.size())
        return actions[0].name();
    return QString();
}

QString MimeLoader::defaultAppIcon(const QString &mimeType) const
{
    QString icon;
    auto actions = ContentAction::actionsForMime(mimeType);
    if (actions.size())
        icon = actions[0].icon();
    qDebug() << icon;
    return icon;
}
