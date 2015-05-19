#ifndef MIMELOADER_H
#define MIMELOADER_H

#include <QtCore/QMimeDatabase>

#include "mimetypemodel.h"

class MimeLoader : public QObject
{
    Q_OBJECT
public:
    explicit MimeLoader();

    Q_INVOKABLE QStringList categories() const;
    Q_INVOKABLE MimetypeModel* modelForCategory(const QString &category) const;

    Q_INVOKABLE bool hasDefaultApp(const QString &mimeType) const;
    Q_INVOKABLE QString defaultAppName(const QString &mimeType) const;
    Q_INVOKABLE QString defaultAppIcon(const QString &mimeType) const;

private:
    QMimeDatabase db_;
    QHash<QString, MimetypeModel*> models_;
};

#endif // MIMELOADER_H
