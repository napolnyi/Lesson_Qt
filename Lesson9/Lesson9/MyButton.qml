import QtQuick 2.0

//BorderImage {

//    property alias text: _txt.text
//    signal clicked

//    source: marea.pressed ? "qrc:///image/start-button.png" : "qrc:///image/start-button-pressed.png"
//    width: 50
//    height: 25
//    //border {left:15; right: 15; top: 12; bottom: 12}


//    Text {
//        id: _txt
//        width: 100
//        height: 100
//        text: qsTr("Save")
//        color: "red"

//    }

//    MouseArea{

//        id:marea
//        anchors.fill:parent
//        onClicked: parent.clicked()
//        onPressed: {

//        }
//        onReleased: {

//        }

//    }

//}
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
