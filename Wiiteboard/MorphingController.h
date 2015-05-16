#ifndef MorphingController_h
#define MorphingController_h

#include "QuadrangleMorphing.h"
#include "MouseMovement.h"
#include "InputHandling.h"
#include "Rectangle.h"
#include "Point.h"
#include <cmath>

class MorphingController
{
public:
	MorphingController();
	bool MorphingController::addCalibrationPoint(float x, float y);
	bool MorphingController::finalCalibration();
	bool MorphingController::deleteLastCalibrationPoint();
	void MorphingController::resetCalibration();
	void MorphingController::getNewData(bool bitValue);
	Point MorphingController::getNewIRPoint(float x, float y);
	void MorphingController::executeMouseAction(Point mousePoint, PenAction penAction);
	static const int WIIMOTE_CAMERA_HEIGHT = 768;
	static const int WIIMOTE_CAMERA_WIDTH = 1024;
	~MorphingController();
private:
	QuadrangleMorphing MorphingController::quadrangleMorphing;
	MouseMovement MorphingController::mouseMovement;
	InputHandling MorphingController::inputHandling;
	uschi::Rectangle MorphingController::calibrationRectangle;
	std::vector<int> MorphingController::lastBitValues;
	PenAction MorphingController::penAction;
};

#endif