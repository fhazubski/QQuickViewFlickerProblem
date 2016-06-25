import QtQuick 2.0

Item {
    id: mainObject

    function setSize(size) {
        width = size.width
        height = size.height
    }

    Rectangle {
        width: 100
        height: 100
        color: "red"
    }

    Rectangle {
        id: frame
        anchors.fill: parent
        anchors.margins: border.width
        color: "transparent"
        border.width: 1
        border.color: "black"
    }
}
