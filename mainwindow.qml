import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Controls 1.2
import com.mvas.yasem.WebViewQml 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 1000
    height: 1000
    color: "white"

    WebViewQml  {
        id: web_view
        objectName: "web_view"
        anchors.fill: parent
        enabled: true
    }

    Component.onCompleted: {

    }
}
