import QtQuick 2.0

Rectangle {

    property alias text: _txt.text
    width: 50
    height: 30
    color: "white"
    signal clicked
    BorderImage {
        signal clicked
        id:_brd
        width: 50
        height: 50
        source: marea.pressed ? "qrc:///image/start-button.png" : "qrc:///image/start-button-pressed.png"
    }

    Text
    {
        id: _txt
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.fill: parent
        color: marea.pressed ?  "Red" : "black"
    }
    MouseArea
    {
        id: marea
        anchors.fill: _brd
        onClicked: parent.clicked()
    }
}
