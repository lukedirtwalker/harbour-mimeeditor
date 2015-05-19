import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page

    property alias title: header.title
    property alias description: description.value
    property alias preferredSuffix: preferredSuffix.value
    property alias suffixes: suffixes.value

    property string mimeName

    SilicaFlickable {
        anchors.fill: parent
        contentHeight: content.height

        Column {
            id: content
            width: parent.width

            PageHeader { id: header }

            DetailItem {
                id: description
                label: qsTr("Description")
            }

            DetailItem {
                id: preferredSuffix
                label: qsTr("PreferredSuffix")
            }

            DetailItem {
                id: suffixes
                label: qsTr("Suffixes")
            }

            Column {
                width: parent.width
                visible: MimeLoader.hasDefaultApp(mimeName)

                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: MimeLoader.defaultAppName(mimeName)
                }

                Image {
                    property string sourceString: MimeLoader.defaultAppIcon(mimeName)
                    enabled: sourceString !== ""
                    source: "image://theme/" + sourceString
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }
}
