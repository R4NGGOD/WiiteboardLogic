#include "stdafx.h"
#include "MouseMovement.h"
//#include "MouseInputDLL.h"




static void leftClickUp() {
	//leftUp();
}
static void leftClickDown() {
	//leftDown();
}
static void rightClickUp() {
	//rightUp();
}

static void rightClickDown() {
	//rightDown();
}

static void setPosition(int x, int y) {
	//setPosition(x, y);
}

static void executePenAction(PenAction penAction) {
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