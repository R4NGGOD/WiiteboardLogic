#ifndef MorphingController_h
#define MorphingController_h

#include "QuadrangleMorphing.h"
#include "InputHandling.h"
#include "Rectangle.h"
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
	void MorphingController::getNewIRPoint(float x, float y);
	~MorphingController();
private:
	QuadrangleMorphing MorphingController::quadrangleMorphing;
	InputHandling MorphingController::inputHandling;
	Rectangle MorphingController::calibrationRectangle;
	std::vector<int> MorphingController::lastBitValues;
	int MorphingController::WIIMOTE_HEIGHT = 768;
	int MorphingController::WIIMOTE_WIDTH = 1024;
};

#endif