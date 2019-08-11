import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import QuickPromise 1.0
import QuickFuture 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button{
        id: btn
        text: "Begin"
        anchors.centerIn: parent
        onClicked: {
            var fCapLeft = Actions.captureLeftCamera();
            var fCapRight = Actions.captureRightCamera();
            var pCapLeft = Future.promise(fCapLeft);
            var pCapRight = Future.promise(fCapRight);

            var pConstruct = Q.all([pCapLeft, pCapRight]);
            pConstruct.then(function(value){
                return Future.promise(Actions.construct(value));
            },function(value){
                console.log("capturing failed...");
            }).then(function(value){
                return Future.promise(Actions.save(value));
            });
//            var pSave = Q.promise();
//            pSave.then(function(value){
//                Actions.save(value);
//            });
//            pConstruct.then(function(value){
//                pSave.resolve(value);
//            });
        }
    }
}
