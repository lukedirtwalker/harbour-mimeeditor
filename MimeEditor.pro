# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = harbour-mimeeditor

CONFIG += sailfishapp

SOURCES += src/MimeEditor.cpp \
    src/mimetypemodel.cpp \
    src/mimeitem.cpp \
    src/mimeloader.cpp

OTHER_FILES += qml/MimeEditor.qml \
    rpm/MimeEditor.changes.in \
    rpm/MimeEditor.spec \
    translations/*.ts \
    qml/pages/MimeCategoryPage.qml \
    qml/pages/MimeCategoriesPage.qml \
    harbour-mimeeditor.desktop \
    qml/pages/MimeDetails.qml

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

INCLUDEPATH += /usr/include/contentaction5
PKGCONFIG += contentaction5

CONFIG += c++11

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/harbour-mimeeditor-de.ts

HEADERS += \
    src/mimetypemodel.h \
    src/mimeitem.h \
    src/mimeloader.h

