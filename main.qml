import QtQuick 2.5
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    id: appWindow
    visible: true
    width: 1366
    height: 760
    color: "black"
    title: qsTr("Barnes-Hut simulation")

    Image {
        anchors.centerIn: parent
        source: "img/BlueSpace.jpg"
    }

    //next steps in improving code
    //timer for faster updating than clicking
    property var coordinatesX
    property var coordinatesY

    Button {
        id: updateButton
        x: parent.width - width
        y: parent.height - height
        width: parent.width / 10
        height: parent.height / 12
        text: qsTr("MANUAL")
        font.pixelSize: parent.height / 30
        font.bold: true
        onClicked: {
            updatebh.nextStep();
            object0.x = updatebh.get0x() - object0.width/2;
            object0.y = updatebh.get0y() - object0.width/2;
            object1.x = updatebh.get1x() - object1.width/2;
            object1.y = updatebh.get1y() - object1.width/2;
            object2.x = updatebh.get2x() - object2.width/2;
            object2.y = updatebh.get2y() - object2.width/2;
            object3.x = updatebh.get3x() - object3.width/2;
            object3.y = updatebh.get3y() - object3.width/2;
            object4.x = updatebh.get4x() - object4.width/2;
            object4.y = updatebh.get4y() - object4.width/2;
            object5.x = updatebh.get5x() - object5.width/2;
            object5.y = updatebh.get5y() - object5.width/2;
            object6.x = updatebh.get6x() - object6.width/2;
            object6.y = updatebh.get6y() - object6.width/2;
            object7.x = updatebh.get7x() - object7.width/2;
            object7.y = updatebh.get7y() - object7.width/2;
            centerMass.x = updatebh.getcx();
            centerMass.y = updatebh.getcy();
            bodies.text = "direct: " + updatebh.getB();
            centers.text = "indirect: " + updatebh.getC();
        }
    }
    Button {
        id: start
        x: parent.width - width
        y: parent.height - 4.1 * height
        width: parent.width / 10
        height: parent.height / 12
        text: qsTr("START")
        font.pixelSize: parent.height / 30
        font.bold: true
        onClicked: {
            time.running = true;
        }
    }
    Button {
        id: stop
        x: parent.width - width
        y: parent.height - 3 * height
        width: parent.width / 10
        height: parent.height / 12
        text: qsTr("STOP")
        font.pixelSize: parent.height / 30
        font.bold: true
        onClicked: {
            time.running = false;
        }
    }
    Timer {
        id: time
        interval: 90
        repeat: true
        onTriggered: {
            updatebh.nextStep();
            object0.x = updatebh.get0x() - object0.width/2;
            object0.y = updatebh.get0y() - object0.width/2;
            object1.x = updatebh.get1x() - object1.width/2;
            object1.y = updatebh.get1y() - object1.width/2;
            object2.x = updatebh.get2x() - object2.width/2;
            object2.y = updatebh.get2y() - object2.width/2;
            object3.x = updatebh.get3x() - object3.width/2;
            object3.y = updatebh.get3y() - object3.width/2;
            object4.x = updatebh.get4x() - object4.width/2;
            object4.y = updatebh.get4y() - object4.width/2;
            object5.x = updatebh.get5x() - object5.width/2;
            object5.y = updatebh.get5y() - object5.width/2;
            object6.x = updatebh.get6x() - object6.width/2;
            object6.y = updatebh.get6y() - object6.width/2;
            object7.x = updatebh.get7x() - object7.width/2;
            object7.y = updatebh.get7y() - object7.width/2;
            centerMass.x = updatebh.getcx();
            centerMass.y = updatebh.getcy();
            bodies.text = "direct: " + updatebh.getB();
            centers.text = "indirect: " + updatebh.getC();
        }
    }

    Text {
        id: bodies
        anchors.right: parent.right
        text: "direct: "
        font.pixelSize: 25
        color: "white"
    }
    Text {
        id: centers
        anchors.top: bodies.bottom
        anchors.right: parent.right
        text: "indirect: "
        font.pixelSize: 25
        color: "white"
    }

    Image {
        id: object0
        width: updatebh.get0m();
        fillMode: Image.PreserveAspectFit
        source: "img/2aae0e25c02fe03e8b22437d69d6802c.png"
    }
    Text {
        x: object0.x
        y: object0.y - height
        text: (object0.width != 0.1) ? "(" + object0.x + ", " + object0.y + ")" : ""
        font.pixelSize: 15
        color: "white"
    }
    Image {
        id: object1
        width: updatebh.get1m();
        fillMode: Image.PreserveAspectFit
        source: "img/asteroid.png"
    }
    Text {
        x: object1.x
        y: object1.y - height
        text: (object1.width != 0.1) ? "(" + object1.x + ", " + object1.y + ")" : ""
        font.pixelSize: 15
        color: "white"
    }
    Image {
        id: object2
        width: updatebh.get2m();
        fillMode: Image.PreserveAspectFit
        source: "img/asteroid-huge.png"
    }
    Text {
        x: object2.x
        y: object2.y - height
        text: (object2.width != 0.1) ? "(" + object2.x + ", " + object2.y + ")" : ""
        font.pixelSize: 15
        color: "white"
    }
    Image {
        id: object3
        width: updatebh.get3m();
        fillMode: Image.PreserveAspectFit
        source: "img/2aae0e25c02fe03e8b22437d69d6802c.png"
    }
    Text {
        x: object3.x
        y: object3.y - height
        text: (object3.width != 0.1) ? "(" + object3.x + ", " + object3.y + ")" : ""
        font.pixelSize: 15
        color: "white"
    }
    Image {
        id: object4
        width: updatebh.get4m();
        fillMode: Image.PreserveAspectFit
        source: "img/asteroid.png"
    }
    Text {
        x: object4.x
        y: object4.y - height
        text: "(" + object4.x + ", " + object4.y + ")"
        font.pixelSize: 15
        color: "white"
    }
    Image {
        id: object5
        width: updatebh.get5m();
        fillMode: Image.PreserveAspectFit
        source: "img/2aae0e25c02fe03e8b22437d69d6802c.png"
    }
    Text {
        x: object5.x
        y: object5.y - height
        text: "(" + object5.x + ", " + object5.y + ")"
        font.pixelSize: 15
        color: "white"
    }
    Image {
        id: object6
        width: updatebh.get6m();
        fillMode: Image.PreserveAspectFit
        source: "img/asteroid-huge.png"
    }
    Text {
        x: object6.x
        y: object6.y - height
        text: "(" + object6.x + ", " + object6.y + ")"
        font.pixelSize: 15
        color: "white"
    }
    Image {
        id: object7
        width: updatebh.get7m();
        fillMode: Image.PreserveAspectFit
        source: "img/asteroid-huge.png"
    }
    Text {
        x: object7.x
        y: object7.y - height
        text: "(" + object7.x + ", " + object7.y + ")"
        font.pixelSize: 15
        color: "white"
    }

    Rectangle {
        id:centerMass
        width: 5
        height: width
        color: "red"
    }
}
