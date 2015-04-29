#include "stdafx.h"
#include "MorphingController.h"
#include "MouseMovement.h"




MorphingController::MorphingController()
{
	quadrangleMorphing = QuadrangleMorphing();
	inputHandling = InputHandling();
	calibrationRectangle = Rectangle();
}

bool MorphingController::addCalibrationPoint(float x, float y) {
	if (calibrationRectangle.getVector().size() <= 4) {
		calibrationRectangle.addPoint(Point(x * MorphingController::WIIMOTE_CAMERA_WIDTH, y * MorphingController::WIIMOTE_CAMERA_HEIGHT, 0));
		return true;
	}
	return false;
}

void MorphingController::resetCalibration() {
	calibrationRectangle = Rectangle();
}

bool MorphingController::deleteLastCalibrationPoint() {
	std::vector<Point> rectanglePoints = calibrationRectangle.getVector();
	if (rectanglePoints.size() > 0) {
		calibrationRectangle.getVector().pop_back();
		return true;
	}
	return false;
}

bool MorphingController::finalCalibration() {
	if (calibrationRectangle.getVector().size() == 4) {
		quadrangleMorphing.setMorphableQuadrangle(calibrationRectangle);
		quadrangleMorphing.startQuadrangleTransformation();
		return true;
	} 
	return false;

}

void MorphingController::getNewData(bool bitValue) {
	PenAction penAction = MOVE_MOUSE;
	if (inputHandling.receiveBit(bitValue)) {
		penAction = inputHandling.getPenAction();
	} 
	executeMouseAction(lastPoint, penAction);
}

void MorphingController::getNewIRPoint(float x, float y) {
	lastPoint = quadrangleMorphing.startPointTransformation(Point(x * MorphingController::WIIMOTE_CAMERA_WIDTH, y * MorphingController::WIIMOTE_CAMERA_HEIGHT, 0));
	
}

void MorphingController::executeMouseAction(Point mousePoint, PenAction penAction) {
	MouseMovement::setPosition(mousePoint.getX(), mousePoint.getY());
	switch (penAction)
}

MorphingController::~MorphingController()
{
}
