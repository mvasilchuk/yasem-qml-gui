import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.1
import QtQuick.Window 2.1
import com.mvas.yasem.WebViewQml 1.0
import QtWebKit 3.0

ApplicationWindow {
    visible: true
    width: 800
    height: 800
    color: "white"

    Label {
        text: "Hello, world"
    }

    WebViewQml  {
        //anchors.fill: parent

        /*Component.onCompleted: {
            console.log("parent completed!!!")
            //qmlInit()
           // rect(0, 0, 400, 500)
            //load("http://google.com")
        }*/

    }
}

