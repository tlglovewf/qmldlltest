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
		id: rectangle
		x: 350
		y: 30
		width: 300
		height: 100
	}

	Keys.onUpPressed: rectangle.y -= 10
    Keys.onDownPressed: rectangle.y += 10
    Keys.onLeftPressed: rectangle.x += 10  // ԭ���о�����������ܣ�������д�����ޡ�����ע
    Keys.onRightPressed: rectangle.x -= 10
}
