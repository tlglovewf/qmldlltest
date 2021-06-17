import QtQuick 2.12
import QtQuick.Window 2.12
import test.mymodule 1.0

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
        height: 100
    }

	RedRect
	{
		x: 350
		y: 30
		width: 300
		height: 100
	}
}
