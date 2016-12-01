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
    }

    Component.onCompleted:  {
        print("name :: " + Manager.name + " number : " + Manager.number);
    }

    Timer{
        id : timer
        interval : 2000
        running : true
        repeat : true
        onTriggered:  {
            Manager.number = (Math.random() * 100).toFixed(0);
        }
    }

    Connections {
        target : Manager
        onNumberChanged : {
            print("Number changed : " + Manager.number);
        }
    }

}
