#pragma once
#include "PenAction.h";
class MouseMovement
{
public:
	MouseMovement() {};
	static void leftClick();
	static void leftClickUp();
	static void leftClickDown();
	static void rightClick();
	static void rightClickUp();
	static void rightClickDown();
	static void setPosition(int x, int y);
	static void executePenAction(PenAction penAction);
	~MouseMovement() {};
};

		