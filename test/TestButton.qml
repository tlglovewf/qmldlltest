import QtQuick 2.3

Rectangle {
    width: 200
    height: 100
	signal test
	border.color: "green"
	property int value:0
    Text {
        anchors.centerIn: parent
        text: "Signal"
    }

   MouseArea{
	 id: mouse
   	 anchors.fill: parent

   }
   onTest:{
   	console.log("test")
   }
   
   onValueChanged:{
   	console.log(value)
   }

   function dosomething(){
	console.log("do something")
   }

   Component.onCompleted: {
        console.log("The rectangle's value is", value)
		mouse.clicked.connect(test)	  //信号连接信号 disconnect 断开连接
		mouse.clicked.connect(dosomething) //信号连接方法
    }
}
