import QtQuick 2.0
import Sailfish.Silica 1.0

import harbour.smscontrol.ConfiguredControllableDevice 1.0

Page {
    id: page
    property ConfiguredControllableDevice device
    //property SMSHelper smsHelper

    SilicaListView {
        model: device.actions
        id: view
        anchors.fill: parent

        header: Column {
            width: Screen.width
            anchors.margins: Theme.paddingMedium

            PageHeader {
                id: pageHeader
                title: device.description
            }

            Row {
                x: Theme.paddingLarge

                Image {
                    id: systemIcon
                    source: "../images/devices/"+ device.id +".png"
                   // height: parent.height-Theme.paddingLarge
                    height: Theme.iconSizeLarge
                    //anchors.verticalCenter: parent.verticalCenter
                    fillMode: Image.PreserveAspectFit
                    //x: Theme.paddingMedium
                    //width: height *1.5
                }

                Label {
                    //complicated space ...
                    text: "   "
                }

                Column {
                    x: Theme.paddingMedium + Theme.paddingLarge + Theme.iconSizeLarge*2
                    anchors.leftMargin: Theme.paddingMedium
                    //anchors.left: systemIcon.right
                    //anchors.leftMargin: Theme.paddingMedium

                    Label {
                        text: device.name
                        color: Theme.primaryColor
                    }
                    Label {
                        text: device.producer
                        font.pixelSize: Theme.fontSizeSmall
                        color: Theme.secondaryColor
                    }
                    Label {
                        text: device.phonenumber
                        font.pixelSize: Theme.fontSizeSmall
                        color: Theme.secondaryColor
                    }
                }

            }
            SectionHeader {
                text: qsTr("Actions")
            }
        }


        /*section {
            property: 'section'
            delegate: SectionHeader {
                text: section
            }
        }*/



        delegate: ListItem {
            id: listItem
            //menu: contextMenu

            anchors.left: parent.left
            anchors.right: parent.right
            contentHeight: Theme.itemSizeMedium // two line delegate
            ListView.onRemove: animateRemoval(listItem)

            function send() {
              remorseAction("Sending "+model.modelData.name, function() {
                  var cmdStr = model.modelData.command;
                  cmdStr = cmdStr.replace("__", device.password);
                  Qt.openUrlExternally("sms:"+device.phonenumber+"?body=" + cmdStr);
                  //console.log("Sending: {to="+device.phonenumber+"; text="+cmdStr+"}");
                  //console.log("Sending: {to="+device.phonenumber+"; text=Password"+device.password+ model.modelData.command+"}")
              },
              3000)
            }

            Image {
                id: actionIcon
                //source: "../images/actions/"+ model.modelData.type.id + "-" + model.modelData.id +".png"
               // source: "../images/actions/"+ model.modelData.typeName + "-" + model.modelData.id +".png"
                source: "../images/actions/"+ model.modelData.id +".png"
                anchors.verticalCenter: parent.verticalCenter
                height: parent.height-Theme.paddingMedium
                width: height
                x: Theme.paddingLarge
            }

            Column {
                anchors.left: actionIcon.right
                anchors.leftMargin: Theme.paddingMedium
                anchors.verticalCenter: parent.verticalCenter

                Label {
                  id: label
                  anchors.topMargin: Theme.paddingMedium
                  text: model.modelData.name
                  color: listItem.highlighted ? Theme.highlightColor : Theme.primaryColor
                }
                Label {
                  text: model.modelData.command
                //anchors.top: label.bottom
                  font.pixelSize: Theme.fontSizeSmall
                  color: listItem.highlighted ? Theme.highlightColor : Theme.secondaryColor
                }
            }

            onClicked: send()
        }

        VerticalScrollDecorator { flickable: view }
    }
}
