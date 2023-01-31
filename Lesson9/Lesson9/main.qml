import QtQuick 2.12
import QtQuick.Window 2.12
import com.vv.BaseReader 1.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3



Window {
    id:root
    width: 500
    height: 500
    visible: true
    title: qsTr("Planner")


        GridLayout
        {
            rows: 3
            columns: 3
            width: root.width
            height: root.height

                Text
                {
                    id:_txt_1
                    text: qsTr("Name Task")
                    font.family: "Helvetica"
                    font.pointSize: 14




                    Layout.row: 0
                    Layout.column: 0
                }
                Text
                {
                    id:_txt_2
                    text: qsTr("Date")
                    font.family: "Helvetica"
                    font.pointSize: 14



                    Layout.row: 1
                    Layout.column: 0
                }
                Text
                {
                    id:_txt_3
                    width: 150
                    height: 20
                    text: qsTr("Progress")
                    font.family: "Helvetica"
                    font.pointSize: 14




                    Layout.row: 2
                    Layout.column: 0
                }

                TextField
                {
                    id:txt_1
                    width: 150
                    height: 10
                    font.family: "Helvetica"
                    font.pointSize: 14
                    focus: true

                    Layout.row: 0
                    Layout.column: 1
                }
                TextField
                {
                    id:txt_2
                    width: 150
                    height: 10
                    font.family: "Helvetica"
                    font.pointSize: 14

                    Layout.row: 1
                    Layout.column: 1
                }
                TextField
                {
                    id:txt_3
                    width: 150
                    height: 10
                    font.family: "Helvetica"
                    font.pointSize: 14

                    Layout.row: 2
                    Layout.column: 1
                }
                MyButton
                {
                    id:btn_1
                    text: qsTr("Save2")
                    width: 10


                    Layout.row: 2
                    Layout.column: 2
                }

            }

}
