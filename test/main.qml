import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import test.mymodule 1.0
import qt.ColorMaker 1.0
Window {
    visible: true
    width: 680
    height: 480
    title: qsTr("Hello World")

    BlueRect
    {
		x: 20
		y: 30
        width: 300
        height: 300
    }

	RedRect
	{
		x: 350
		y: 30
		width: 300
		height: 300

	}

	Rectangle
	{
		id: colorRect
		x: 20
		y: 360
		width: 300
		height: 30
		color: "green"
		Text 
		{
			id: timeLabel;
			anchors.left: parent.left;
			anchors.leftMargin: 4;
			anchors.top: parent.top;
			anchors.topMargin: 4;
			font.pixelSize: 26;
			text: "hello"
		} 
	}
	ColorMaker 
	{
        id: colorMaker
        color: "blue"
    }

	Button
	{
		objectName: "btnGetTime"
		x: 320
		y: 360
		width:  60
		height: 30
		text: "GetTime"
		onClicked:
		{
			colorMaker.start()
		}
	}

	Button
	{
		x: 320
		y: 400
		width: 60
		height: 30
		text: "popup"
		onClicked:
		{
			secWin.show()
		}
	}

	Component.onCompleted: 
	{
        colorMaker.color = Qt.rgba(0,180,120, 255);
        colorMaker.setAlgorithm(ColorMaker.RandomRGB);
		timeLabel.text = "show time"
    }
	//Á¬½ÓÐÅºÅ²Û
	Connections 
	{
        target: colorMaker;
        onColorChanged:{
            colorRect.color = color;
        }
    }
	Connections 
	{
		target: colorMaker;
		onCurrentTime:
		{
			timeLabel.text = strTime;
			timeLabel.color = colorMaker.timeColor;
		}
    }
}
