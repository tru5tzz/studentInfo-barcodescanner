import QtQuick
import QtMultimedia
import QtQuick.Controls

import com.trungnd.interface 1.0
import com.scythestudio.scodes 1.0

// The root element is the Rectangle
import QtMultimedia 6.0
ApplicationWindow {
    // name this element root
    id: root

    // properties: <name>: <value>
    width: 1280; height: 720

    // color property
    // color: "#4A4A4A"

    visible: true

    VideoOutput {
    id: camera_output
    x: 79
    y: 79
    width: 640
    height: 480

    focus: visible
    fillMode: VideoOutput.PreserveAspectCrop

    }

    // Declare a nested element (child of root)
    SBarcodeScanner {
        id: barcodeScanner

        videoSink: camera_output.videoSink

        captureRect: Qt.rect(camera_output.width / 4, camera_output.height / 4, camera_output.width / 2, camera_output.height / 2)
        x = camera_output.x
        y = camera_output.y

        ipAddress: "192.168.1.101"

        onCapturedChanged: function (captured) {
        scanResultText.text = captured
        resultScreen.visible = true
        barcodeScanner.setProcessing(0)
    }
}

Qt6ScannerOverlay {
    id: scannerOverlay

    //anchors.fill: parent
    x = camera_output.x
    y = camera_output.y

    captureRect: barcodeScanner.captureRect
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
    visible: true
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
    text: BackendInterface.nameTag()
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
