import QtQuick 2.0

Rectangle {
    border.color: "red"
	color: "green"
	signal clicked                                          // signal declarations
	states: State {                                         // states
        name: "selected"
        PropertyChanges { target: border; color: "red" }
    }
	transitions: Transition {                               // transitions
        from: ""; to: "selected"
        ColorAnimation { target: border; duration: 200 }
    }

	Text {
		text: "hello"
		font.bold:   true
		font.italic: true
		font.pixelSize: 20
		font.capitalization: Font.AllUppercase
	}
}
