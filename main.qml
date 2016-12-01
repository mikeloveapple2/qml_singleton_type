import Ho0 1.0
import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    color : "beige"


    Text {
        text: qsTr("qmlRegisterSingletonType")
        anchors.centerIn: parent
    }

    MouseArea {
        id : ma_empty
        anchors.fill:  parent

        onClicked : {
            Qt.quit();
        }

        Text {
            id: txt
            text: qsTr("Text")
            color : "darkgreen"
            width : 100
            height : 100
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 22

            anchors {
                right : parent.right
                bottom : parent.bottom
            }
        }
    }

    Component.onCompleted:  {
        print("name :: " + Manager.name + " number : " + Manager.number);
    }

    Timer{
        id : timer
        interval : 1000
        running : true
        repeat : true
        onTriggered:  {
            Manager.number = (Math.random() * 100).toFixed(0);
        }
    }

    Connections {
        target : Manager
        onNumberChanged : {
            txt.text = Manager.number;
        }
    }

}
