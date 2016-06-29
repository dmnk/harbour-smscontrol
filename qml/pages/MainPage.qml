import QtQuick 2.0
import Sailfish.Silica 1.0

import harbour.smscontrol.ControllableDevice 1.0
//import org.dmnk.ConfiguredControllableDevice 1.0
import harbour.smscontrol.DeviceManager 1.0
import harbour.smscontrol.DeviceStorage 1.0

Page {
    id: page

    DeviceStorage {
        id: deviceStorage
    }
    DeviceManager {
        id: deviceManager
    }

    SilicaListView {
        id: view
        anchors.fill: parent
        model: deviceStorage.controllableDevices

        header: PageHeader {
            title: qsTr("SMS-Control")
        }

        section {
            property: 'modelData.typeName'

            delegate: SectionHeader {
                text: section
            }
        }

        PullDownMenu {
            id: topMenu
            /*MenuItem {
                text: qsTr("About")
                onClicked: pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
            }
            MenuItem {
                text: qsTr("Help")
                onClicked: pageStack.push(Qt.resolvedUrl("HelpPage.qml"))
            }*/
            MenuItem {
                text: qsTr("Disclaimer")
                onClicked: pageStack.push(Qt.resolvedUrl("DisclaimerPage.qml"))
            }
            Label {
                visible: false //
                //visible: view.count == 1
                //anchors.centerIn: parent
                font.pixelSize: Theme.fontSizeSmall
                color: Theme.secondaryColor
                x: Theme.paddingLarge
                text: qsTr("Free Version limited to 1 device!")
            }

            MenuItem {
                visible: true //might also be ommitted, just to remind myself ;)
                //visible: view.count == 0
                text: qsTr("Add Device")
                onClicked: pageStack.push(Qt.resolvedUrl("AddOverviewPage.qml"),
                                          {"deviceStorage": deviceStorage, "deviceManager": deviceManager})
            }

            Label {
                visible: true //
                //visible: view.count == 1
                //anchors.centerIn: parent
                font.pixelSize: Theme.fontSizeSmall
                color: Theme.secondaryColor
                x: Theme.paddingLarge
                text: qsTr("If you like it, please Flattr!  (link in store)")
            }
        }

        /*PushUpMenu {
            MenuItem {
                text: "Listen-in"
            }
        }*/

        ViewPlaceholder {
            enabled: view.count == 0
            text: qsTr("No device")
            hintText: qsTr("Pull down to add devices")
        }

        VerticalScrollDecorator { flickable: view }

        delegate: ListItem {
            id: listItem
            menu: contextMenu
            anchors.left: parent.left
            anchors.right: parent.right
            contentHeight: Theme.itemSizeMedium // two line delegate
            ListView.onRemove: animateRemoval(listItem)

            function remove() {
              remorseAction("Deleting", function() {
                  deviceStorage.removeControllableDevice(model.modelData.phonenumber);
                  view.model = deviceStorage.controllableDevices;
                  //view.model.remove(index)
              })
            }

            Image {
                id: systemIcon
                source: "../images/devices/"+ model.modelData.id +".png"
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
                    text: model.modelData.description
                    color: listItem.highlighted ? Theme.highlightColor : Theme.primaryColor
                }
                Label {
                    text: model.modelData.phonenumber
                    font.pixelSize: Theme.fontSizeSmall
                    color: listItem.highlighted ? Theme.secondaryHighlightColor : Theme.secondaryColor
                }
            }

            Component {
                id: contextMenu
                ContextMenu {
                  MenuItem {
                      text: "Remove"
                      onClicked: remove()
                  }
                  /*MenuItem {
                      text: "Edit"
                      onClicked:  pageStack.push(Qt.resolvedUrl("SecuritySystems_Edit.qml"),
                            {"deviceManager": deviceManager,
                            "securitySystem": model.modelData})
                  }*/
                }
            }

            onClicked: pageStack.push(Qt.resolvedUrl("ActionPage.qml"),
                                            {"device": model.modelData})

        }
    }
}


