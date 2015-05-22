//AUTHOR: Alexander Ciupka

#include "stdafx.h"
#include "MouseMovement.h"
#include <MouseInputDLL.h> 



/*
	execute left Mouse Button up
*/
void MouseMovement::leftClickUp() {
	leftUp();
}

/*
	execute left Mouse Button down
*/
void MouseMovement::leftClickDown() {
	leftDown();
}

/*
	execute right Mouse Button up
*/
void MouseMovement::rightClickUp() {
	rightUp();
}

/*
	execute right Mouse Button down
*/
void MouseMovement::rightClickDown() {
	rightDown();
}

/*
	set the Mouse Position
*/
void MouseMovement::setMousePosition(int x, int y) {
	//Its not a mathematic coordinatic system -> root in the upper left corner!
	setPosition(x, 65665 - y);
}

/*
	receives a PenAction and checks what to do
*/
void MouseMovement::executePenAction(PenAction penAction) {
	switch (penAction) {
		case RIGHT_CLICK_DOWN:
			rightClickDown();
			break;
		case RIGHT_CLICK_UP:
			rightClickUp();
			break;
		case LEFT_CLICK_DOWN:
			leftClickDown();
			break;
		case LEFT_CLICK_UP:
			leftClickUp();
			break;
	}
}