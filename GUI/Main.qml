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

    StackLayout {
        id: stack 
        anchors.fill: parent 
        currentIndex: 0
        Item {
            Column {
                anchors.centerIn: parent 
                spacing: 20 

                Text {
                    text: "Choose game mode"
                    font.pixelSize: 28 
                }
                Button {
                    text: "Player vs Player"
                    x: 75
                    onClicked: {
                        stack.currentIndex = 1
                        game.resetBoard()
                    }
                }
                Button {
                    text: "Player vs AI"
                    x: 75
                    onClicked: {
                        stack.currentIndex = 2
                        game.resetBoard()
                    }
                }
            }
        }

        Item {
            Column {
                anchors.centerIn: parent 
                spacing: 20 

                Text {
                    text: qsTr("Vs Human")
                    font.pixelSize: 24
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    text: game.status 
                    font.pixelSize: 24
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                RowLayout {
                    GroupBox {
                        GridLayout {
                            columns: 3 
                            Repeater {
                                model: 9

                                Rectangle {
                                    width: 100
                                    height: 100 
                                    border.width: 2

                                    property string cellValue: game.board[index]

                                    Text {
                                        anchors.centerIn: parent 
                                        text: parent.cellValue 
                                        font.pixelSize: 48 
                                    }

                                    MouseArea {
                                        anchors.fill: parent 
                                        onClicked: {
                                            var row = Math.floor(index / 3)
                                            var col = index % 3 
                                            if(parent.cellValue === ""){
                                                game.cellClickedVsHuman(row, col)
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                Button {
                    text: "Back to Main menu"
                    onClicked: {
                        stack.currentIndex = 0
                    }
                }
            }
        }
        Item {
            Column {
                anchors.centerIn: parent 
                spacing: 20 

                Text {
                    text: qsTr("Vs AI")
                    font.pixelSize: 24
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    text: game.status 
                    font.pixelSize: 24
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                RowLayout {
                    GroupBox {
                        GridLayout {
                            columns: 3 
                            Repeater {
                                model: 9

                                Rectangle {
                                    width: 100
                                    height: 100 
                                    border.width: 2

                                    property string cellValue: game.board[index]

                                    Text {
                                        anchors.centerIn: parent 
                                        text: parent.cellValue 
                                        font.pixelSize: 48 
                                    }

                                    MouseArea {
                                        anchors.fill: parent 
                                        onClicked: {
                                            var row = Math.floor(index / 3)
                                            var col = index % 3 
                                            if(parent.cellValue === ""){
                                                game.cellClickedVsAI(row, col)
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                Button {
                    text: "Back to Main menu"
                    onClicked: {
                        stack.currentIndex = 0
                    }
                }
            }
        }
    }
}
