import QtQuick
import QtQuick.Layouts 
import QtQuick.Controls.Basic 

Window {
    id: root 

    width: 640
    height: 480
    visible: true
    title: qsTr("Tic Tac Toe")

    RowLayout {
        anchors.centerIn: parent 
        spacing: 5 

        GroupBox {
            GridLayout {
                columns: 3
                columnSpacing: 5
                rowSpacing: 5

                Repeater {
                    model: 9
                    Rectangle {
                        width: 100 
                        height: 100 
                        border.color: "#333"
                        border.width: 2
                    }
                }
            }
        }
    }
}
