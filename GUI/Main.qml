import QtQuick
import QtQuick.Layouts 
import QtQuick.Controls.Basic 
import TicTacToe

Window {
    id: root 

    width: 640
    height: 480
    visible: true
    title: qsTr("Tic Tac Toe")

    Game {
        id: game
    }
    Text {
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter

        text: game.status
        font.pixelSize: 24
    }
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

                        property string cellValue: game.board[index]

                        Text {
                            anchors.centerIn: parent 
                            font.pixelSize: 48 
                            text: parent.cellValue 
                        }

                        Connections {
                            target: game 
                            function onBoardChanged() {
                                cellValue = game.board[index]
                            }
                        }

                        MouseArea {
                            anchors.fill: parent 
                            onClicked: {
                                var row = Math.floor(index/3)
                                var col = index % 3 
                                if(parent.cellValue === "")
                                {
                                    game.cellClicked(row, col)
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
