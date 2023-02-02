import QtQuick 2.12
import QtQuick.Window 2.12
import com.vv.BaseReader 1.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3




Window {
    id:root
    width: 800
    height: 150
    visible: true
    title: qsTr("Planner")





    BaseReader{
        id:_base
    }


        GridLayout
        {
            rows: 3
            columns: 3
            width: root.width
            height: root.height

 //строка 1
            Rectangle{
                width: 50
                height: 30
                border.color: "Black"
                color: "gray"
                Layout.row: 0
                Layout.column: 0
                Layout.fillWidth: true

                Text
                    {
                        text: qsTr("Name Task")
                        font.family: "Helvetica"
                        font.pointSize: 14
                        anchors.fill: parent
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                    }
            }
            Rectangle{
                width: 150
                height: 30
                border.color: "Black"
                color: "gray"
                Layout.row: 0
                Layout.column: 1
                Layout.fillWidth:true


                TextField
                {
                    id:_tFld_1
                    font.family: "Helvetica"
                    font.pointSize: 14
                    anchors.fill: parent
                }
            }
 //строка 2
            Rectangle{
                width: 50
                height: 30
                border.color: "Black"
                color: "gray"
                Layout.row: 1
                Layout.column: 0
                Layout.fillWidth:true

                Text
                    {
                        text: qsTr("Date")
                        font.family: "Helvetica"
                        font.pointSize: 14
                        anchors.fill: parent
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                    }
            }

            Rectangle{
                width: 150
                height: 30
                border.color: "Black"
                color: "gray"
                Layout.row: 1
                Layout.column: 1
                Layout.fillWidth:true


                TextField
                {
                    id:_tFld_2
                    anchors.fill: parent
                    font.family: "Helvetica"
                    font.pointSize: 14
                }
            }
//Строка 3
            Rectangle{
                width: 50
                height: 30
                border.color: "Black"
                color: "gray"
                Layout.row: 2
                Layout.column: 0
                Layout.fillWidth:true

                Text
                    {
                        text: qsTr("Progress")
                        font.family: "Helvetica"
                        font.pointSize: 14
                        anchors.fill: parent
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                    }
            }

            Rectangle{
                width: 150
                height: 30
                border.color: "Black"
                color: "gray"
                Layout.row: 2
                Layout.column: 1
                Layout.fillWidth:true


                TextField
                {
                    id:_tFld_3
                    anchors.fill: parent
                    font.family: "Helvetica"
                    font.pointSize: 14
                }
            }
//Копка

                MyButton
                {
                    id:btn_1
                    text: qsTr("SAVE")
                    width: 150
                    height: 50
                    Layout.rowSpan: 2
                    Layout.column: 2
                    Layout.alignment: Qt.AlignBottom
                    onClicked: {
                        _base.saveBase(_tFld_1.text, _tFld_2.text, _tFld_3.text )

                    }

                }
            }

}
