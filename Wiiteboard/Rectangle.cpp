#include "stdafx.h"
#include <vector>
#include "Rectangle.h"

namespace uschi {

	bool Rectangle::fillVector(std::vector<Point> vector) {
		if (vector.size() != 4) {
			points = vector;
			return true;
		}
		return false;
	}

	std::vector<Point> Rectangle::getVector() {
		return this->points;
	}

	void Rectangle::addPoint(Point point) {
		this->points.push_back(point);
	}

	bool Rectangle::isInsideOf(Point point) {

		return false;
	}
}