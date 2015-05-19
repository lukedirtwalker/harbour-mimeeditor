import QtQuick 2.0
import Sailfish.Silica 1.0


Page {
    id: categoryPage

    property string category
    property alias categoryModel: listView.model

    SilicaListView {
        id: listView
        anchors.fill: parent
        header: PageHeader {
            title: categoryPage.category
        }
        delegate: ListItem {
            id: delegate
            width: parent.width

            Label {
                anchors {
                    left: parent.left
                    leftMargin: Theme.paddingLarge
                    right: parent.right
                    rightMargin: Theme.paddingLarge
                    verticalCenter: parent.verticalCenter
                }
                color: delegate.highlighted ? Theme.highlightColor : Theme.primaryColor
                text: name
                truncationMode: TruncationMode.Fade
            }

            onClicked: pageStack.push(Qt.resolvedUrl("MimeDetails.qml"),
                                      {"title": name,
                                       "description": description,
                                       "preferredSuffix": preferredSuffix,
                                       "suffixes": suffixes,
                                       "mimeName": mimeName
                                      })
        }

        VerticalScrollDecorator {}
    }
}





