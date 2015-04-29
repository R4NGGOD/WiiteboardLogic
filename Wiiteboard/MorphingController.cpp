#include "stdafx.h"
#include "MorphingController.h"




MorphingController::MorphingController()
{
	quadrangleMorphing = QuadrangleMorphing();
	inputHandling = InputHandling();
	calibrationRectangle = Rectangle();
}

bool MorphingController::addCalibrationPoint(float x, float y) {
	if (calibrationRectangle.getVector().size() <= 4) {
		calibrationRectangle.addPoint(Point(x, y, 0));
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
	inputHandling.receiveBit(bitValue);
}

void MorphingController::getNewIRPoint(float x, float y) {
	Point finalPoint = quadrangleMorphing.startPointTransformation(Point(x, y, 0));
	//TODO stuff
}

MorphingController::~MorphingController()
{
}
