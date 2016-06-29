import QtQuick 2.0
import Sailfish.Silica 1.0

import harbour.smscontrol.DeviceManager 1.0
import harbour.smscontrol.ControllableDevice 1.0
import harbour.smscontrol.DeviceStorage 1.0

Page {
    id: page

    property DeviceStorage deviceStorage
    property DeviceManager deviceManager

//    DeviceManager {
//        id: deviceManager
//    }

    SilicaListView {
        id: view
        anchors.fill: parent
        model: deviceManager.devices
        header: PageHeader {
            title: "Select yours"
        }

        ViewPlaceholder {
            enabled: view.count == 0
            text: "No device"
            hintText: "Something went terribly wrong\nTry to reinstall and \ncontact the developer\n if the error persists"
        }

        section {
            property: 'modelData.typeName'

            delegate: SectionHeader {
                text: section
            }
        }

        delegate: ListItem {
            id: listItem
            anchors.left: parent.left
            anchors.right: parent.right
            contentHeight: Theme.itemSizeMedium

            Image {
                id: systemIcon
                source: "../images/devices/"+model.modelData.id+".png"
                height: parent.height-Theme.paddingLarge
                anchors.verticalCenter: parent.verticalCenter
                fillMode: Image.PreserveAspectFit
                x: Theme.paddingLarge
                width: height *1.5
            }
            Column {
                anchors.left: systemIcon.right
                anchors.leftMargin: Theme.paddingMedium
                anchors.verticalCenter: parent.verticalCenter

                Label {
                    text: model.modelData.name
                    color: listItem.highlighted ? Theme.highlightColor : Theme.primaryColor
                }
                Label {
                    text: model.modelData.producer
                    font.pixelSize: Theme.fontSizeSmall
                    color: listItem.highlighted ? Theme.secondaryHighlightColor : Theme.secondaryColor
                }
            }

            onClicked: pageStack.replace(Qt.resolvedUrl("AddDetailPage.qml"),
                            {"device": model.modelData,
                            "deviceStorage": deviceStorage});
            /*onClicked: pageStack.push(Qt.resolvedUrl("AddDetailPage.qml"),
                {"device": model.modelData,
                "deviceStorage": deviceStorage});*/

             VerticalScrollDecorator { flickable: view }
       }
   }
}
