import QtQuick 2.0
import Sailfish.Silica 1.0
//import org.dmnk.DeviceManager 1.0
import harbour.smscontrol.DeviceStorage 1.0
import harbour.smscontrol.ControllableDevice 1.0

Dialog {
    id: page
    property alias name: nameInput.text
    property alias phonenumber: phoneInput.text
    property alias password: passwordInput.text
    //property DeviceManager deviceManager
    property DeviceStorage deviceStorage
    property ControllableDevice device

    canAccept: name != "" && phonenumber != "" && password != ""

    onAccepted: {
        deviceStorage.addControllableDevice(device.id, page.name, page.phonenumber, page.password, device.type)
        //console.log("Adding: " + device.id +" name: "+ page.name + " nr"+ page.phonenumber + " pass:"+page.password)
        /*deviceManager.addSecuritySystem(page.phonenumber, page.name, page.phonenumber,
                            page.password)*/
    }
    onCanceled: {
        //pageStack.replace(Qt.resolvedUrl("DevicePage.qml"));
    }




    SilicaFlickable {
        anchors.fill: parent
        contentHeight: column.height + Theme.paddingLarge

        VerticalScrollDecorator {}
        Column {
            id: column
            width: parent.width

            DialogHeader {
                acceptText: qsTr("Add Device")
            }

            Row {
                id: listItem
                spacing: Theme.paddingMedium
                //anchors.left: parent.left
                //anchors.right: parent.right
                //contentHeight: Theme.itemSizeMedium
                Image {
                    id: addIcon
                    source: "image://theme/icon-l-add"
                    height: Theme.iconSizeLarge
                    fillMode: Image.PreserveAspectFit
                    anchors.leftMargin: Theme.paddingLarge
                    //x: Theme.paddingLarge
                }

                /*Label {
                    text: qsTr("Adding: ")
                }*/

                Image {
                    id: systemIcon
                    //source: "qrc:///devices/"+device.id+".png"
                    source: "../images/devices/"+ device.id +".png"
                   // height: parent.height-Theme.paddingLarge
                    height: Theme.iconSizeLarge
                    //anchors.verticalCenter: parent.verticalCenter
                    fillMode: Image.PreserveAspectFit
                    //x: Theme.paddingMedium
                    //width: height *1.5
                }
                Column {
                    //anchors.left: systemIcon.right
                    anchors.leftMargin: Theme.paddingMedium

                    Label {
                        text: device.name
                        color: Theme.primaryColor
                    }
                    Label {
                        text: device.producer
                        font.pixelSize: Theme.fontSizeSmall
                        color: Theme.secondaryColor
                    }
               }
            }

            TextField {
                id: nameInput
                width: parent.width
                label: qsTr("System-Name")
                placeholderText: qsTr("Name of the System")
                focus: true
                horizontalAlignment: Theme.textAlignment
                EnterKey.enabled: text.length > 0
                EnterKey.iconSource: "image://theme/icon-m-enter-next"
                EnterKey.onClicked: phoneInput.focus = true
            }

            TextField {
                id: phoneInput
                width: parent.width
                inputMethodHints: Qt.ImhDialableCharactersOnly
                label: qsTr("Phone number")
                placeholderText: qsTr("Phone number of the control")
                //placeholderColor: Theme.secondaryColo
                //color: Theme.highlightColor
                horizontalAlignment: Theme.textAlignment
                EnterKey.enabled: text.length > 0
                EnterKey.iconSource: "image://theme/icon-m-enter-next"
                EnterKey.onClicked: passwordInput.focus = true
            }

            TextField {
                id: passwordInput
                width: parent.width
                inputMethodHints: Qt.ImhFormattedNumbersOnly
                label: qsTr("Password")
                placeholderText: qsTr("Remote password");
                //horizontalAlignment: textAlignment
                EnterKey.enabled: true
                EnterKey.iconSource: "image://theme/icon-m-enter-accept"
                //EnterKey.onClicked: parent.focus = true
                EnterKey.onClicked: page.accept()
            }
        }
    }
}
