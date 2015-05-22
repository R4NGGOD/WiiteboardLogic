//AUTHOR: Alexander Ciupka

#include "stdafx.h"
#include "MorphingController.h"
#include "MouseMovement.h"
#include <iostream>




MorphingController::MorphingController()
{
	quadrangleMorphing = QuadrangleMorphing();
	mouseMovement = MouseMovement();
	inputHandling = InputHandling();
	calibrationRectangle = Rectangle();
}

/*
	Method to add one of the four calibration points
	returns true if there are not more than 4 points already and if the point was transformed correctly
*/
bool MorphingController::addCalibrationPoint(float x, float y) {
	if (calibrationRectangle.getVector().size() <= 4) {
		calibrationRectangle.addPoint(Point(x * MorphingController::WIIMOTE_CAMERA_WIDTH, y * MorphingController::WIIMOTE_CAMERA_HEIGHT, 0));
		return true;
	}
	return false;
}

/*
	resets all points of the calibration rectangle
*/
void MorphingController::resetCalibration() {
	calibrationRectangle = Rectangle();
}

/*
	Reset and delete the last calibration point
	returns true if there is a deletable point  
*/
bool MorphingController::deleteLastCalibrationPoint() {
	std::vector<Point> rectanglePoints = calibrationRectangle.getVector();
	if (rectanglePoints.size() > 0) {
		calibrationRectangle.getVector().pop_back();
		return true;
	}
	return false;
}

/*
	calls methods to transform the received calibration rectangle into a 1x1 Quadangle

*/
bool MorphingController::finalCalibration() {
	if (calibrationRectangle.getVector().size() == 4) {
		quadrangleMorphing.setMorphableQuadrangle(calibrationRectangle);
		quadrangleMorphing.startQuadrangleTransformation();
		return true;
	} 
	return false;

}

/*
	receives one bit and sets the penAction
*/
void MorphingController::getNewData(bool bitValue) {
	penAction = MOVE_MOUSE;
	if (inputHandling.receiveBit(bitValue)) {
		penAction = inputHandling.getPenAction();
	} 
	
}

/*
	receives a coordinate where the wiimote saw a infraredPoint
*/
Point MorphingController::getNewIRPoint(float x, float y) {
	//Transform the received point
	Point point = quadrangleMorphing.startPointTransformation(Point(x * MorphingController::WIIMOTE_CAMERA_WIDTH, y * MorphingController::WIIMOTE_CAMERA_HEIGHT, 0));
	std::cout << quadrangleMorphing.getFinalSquare().isInsideOf(point);
	//checks if the received and transformed point is inside of the 1x1 quadangle
	if (quadrangleMorphing.getFinalSquare().isInsideOf(point)) {
		//returns the point
		return Point(point.getX() * 65665, point.getY() * 65665, 0);
	}
}

/*
	executes a mouse action
*/
void MorphingController::executeMouseAction(Point mousePoint, PenAction penAction) {
	mouseMovement.setMousePosition(mousePoint.getX(), mousePoint.getY());
	mouseMovement.executePenAction(penAction);
}

MorphingController::~MorphingController()
{
}
