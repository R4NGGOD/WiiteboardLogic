//AUTHOR: Alexander Ciupka

#include "stdafx.h"
#include <vector>
#include "Rectangle.h"

namespace uschi {

	/*
		replace the points vector with the received vector, if this vector has 4 Points in it.
	*/
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

	/*
		works for the final 1x1 quadangle.
		return false if the received point is not in the rectangle (x or y smaller than 0 or greater than 1)
	*/
	bool Rectangle::isInsideOf(Point point) {
		if (point.getX() < 0 || point.getY() < 0 ||
			point.getX() > 1 || point.getY() > 1) {
			return false;
		}
		return true;
	}
}