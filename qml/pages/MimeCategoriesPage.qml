import QtQuick 2.0
import Sailfish.Silica 1.0


Page {
    id: page

    // To enable PullDownMenu, place our content in a SilicaFlickable
    SilicaListView {
        anchors.fill: parent

        header: PageHeader {
            title: qsTr("Mime categories")
        }

        model: MimeLoader.categories()

        delegate: ListItem {
            id: listItem
            width: parent.width
            Label {
                anchors {
                    left: parent.left
                    leftMargin: Theme.paddingLarge
                    right: parent.right
                    rightMargin: Theme.paddingLarge
                    verticalCenter: parent.verticalCenter
                }
                text: modelData
                color: listItem.highlighted ? Theme.highlightColor : Theme.primaryColor
            }
            onClicked: pageStack.push(Qt.resolvedUrl("MimeCategoryPage.qml"), {"category": modelData,
                                      "categoryModel": MimeLoader.modelForCategory(modelData)})
        }

        VerticalScrollDecorator { }
    }
}


