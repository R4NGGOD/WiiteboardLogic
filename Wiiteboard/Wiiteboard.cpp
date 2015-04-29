// Wiiteboard.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "QuadrangleMorphing.h"
#include "Point.h"
#include <windows.h>
#include "Rectangle.h"
#include "MouseInputDLL.h"
#include "PenAction.h"
#include <array>
#include "InputHandling.h"

int _tmain(int argc, _TCHAR* argv[])
{
	InputHandling input = InputHandling();
	std::array<bool, 12> test = { 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1 };
	for (bool b : test) {
		if (input.receiveBit(b)) {
			std::cout << "InputHandling -> PenAction: " << input.analyzePenAction() << "\n";
		}
	}

	
	PenAction penA = LEFT_CLICK_DOWN;
	if (penA == LEFT_CLICK_DOWN) {
		penA = MOUSE_DISCONNECT;
	}
	std::cout << penA;
	Point pointA = Point(27, 18, 0);
	Point pointB = Point(25, 381, 0);
	Point pointC = Point(1023, 50, 0);
	Point pointD = Point(700, 1, 0);
	uschi::Rectangle rectangle = uschi::Rectangle();
	rectangle.addPoint(pointA);
	rectangle.addPoint(pointB);
	rectangle.addPoint(pointC);
	rectangle.addPoint(pointD);
	QuadrangleMorphing morphingOfD00M = QuadrangleMorphing(rectangle);
	morphingOfD00M.startQuadrangleTransformation();
	std::cout << morphingOfD00M.getFinalSquare().getVector().at(2).getX();
	Point point = morphingOfD00M.startPointTransformation(Point(500, 19, 0));
	setPosition(point.getX() * 65565, (1 - point.getY()) * 65565);
	std::cout << point.getX() << " " << point.getY();
	Sleep(10000);
}

