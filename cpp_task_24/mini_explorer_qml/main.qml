import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3
import CustomFileViewer 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Mini Explorer (QML)"

    Column {
        spacing: 10
        anchors.fill: parent

        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            TextField {
                id: pathField
                width: 400
                text: fileModel.rootPath
                readOnly: true
            }

            Button {
                text: "Оберіть директорію"
                onClicked: fileDialog.open()
            }
        }

        FileDialog {
            id: fileDialog
            title: "Оберіть директорію"
            folder: fileModel.rootPath
            selectFolder: true
            onAccepted: {
                fileModel.setRootPath(fileDialog.folder.toString().replace("file://", ""))
                pathField.text = fileModel.rootPath
            }
        }

        TreeView {
            anchors.fill: parent
            model: fileModel

            TableViewColumn {
                title: "Ім'я"
                role: "display"
                width: 400
            }
            TableViewColumn {
                title: "Розмір (KB)"
                role: "size"
                width: 150
            }

            delegate: Item {
                width: parent.width
                height: 40

                Row {
                    spacing: 10
                    anchors.verticalCenter: parent.verticalCenter

                    Rectangle {
                        width: 10
                        height: 10
                        color: model.display.startsWith("[DIR]") ? "blue" : "green"
                    }

                    Text {
                        text: model.display
                        font.bold: model.display.startsWith("[DIR]")
                    }

                    Text {
                        text: model.display.startsWith("[DIR]") ? "" : "(" + model.size + " KB)"
                        color: "gray"
                    }
                }
            }
        }
    }

    CustomFileSystemModel {
        id: fileModel
        rootPath: "/home/user" // Початковий шлях (можна змінити)
        nameFilters: ["*.cpp", "*.h"]
    }
}
