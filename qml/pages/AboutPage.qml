import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: about

    SilicaListView {
        anchors.fill: parent
        spacing: Theme.paddingMedium

        contentWidth: parent.width
        contentHeight: col.height

        VerticalScrollDecorator {}

        Column {
            id: col
            spacing: Theme.paddingLarge
            width: parent.width
            PageHeader {
                title: "About"
            }
            SectionHeader {
                text: "Text styling"
            }
            Label {
                id: author
                text: "balbal"
                font.pixelSize: Theme.fontSizeExtraSmall
                wrapMode: Text.WordWrap
            }
        }
    }
}
