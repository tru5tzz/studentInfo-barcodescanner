import QtQuick
import QtMultimedia
import QtQuick.Controls

// The root element is the Rectangle
import QtMultimedia 6.0
Rectangle {
    // name this element root
    id: root

    // properties: <name>: <value>
    width: 1280; height: 720

    // color property
    color: "#4A4A4A"

    // Declare a nested element (child of root)
    MediaPlayer {
        id: camera_input

        source: "no_source"
        videoOutput: camera_output
    }

    VideoOutput {
        id: camera_output
        x: 79
        y: 79
        width: 640
        height: 480

    }

    // Another child of root
    SwitchDelegate {
        id: autoScanSwitch
        x: 237
        y: 579
        width: 175
        height: 49
        text: "Tu dong quet"
        checkable: false
        autoExclusive: false
        checked: false
        display: AbstractButton.TextUnderIcon

    }

    Text {
        id: hello
        x: 832
        y: 120
        visible: false
        color: "#f7f3f3"
        text: "Xin cam on!!!"
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        font.weight: Font.Bold
        font.pointSize: 36
    }

    Text {
        id: studentName
        x: 761
        y: 212
        width: 512
        height: 59
        visible: false
        color: "#fdf9f9"
        text: "Hien thi ten sinh vien"
        horizontalAlignment: Text.AlignHCenter
        font.weight: Font.Bold
        font.bold: true
        font.pointSize: 36

    }
}
/*##^##
Designer {
    D{i:0;formeditorZoom:0.33}
}
##^##*/
