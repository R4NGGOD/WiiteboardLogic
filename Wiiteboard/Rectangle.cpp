#include "stdafx.h"
#include <vector>
#include "Point.h"
#include "Rectangle.h"

class Rectangle {
	
	private:
		std::vector<Point> points;

	Rectangle::Rectangle()
	{
	}

	bool fillVector(std::vector<Point> vector) {
		if (vector.size != 4) {
			points = vector;
			return true;
		}
		return false;
	}

	std::vector<Point> getVector() {
		return this->points;
	}	

	void addPoint(Point point) {
		this->points.push_back(point);
	}

	bool isInsideOf(Point point) {

		return false;
	}

	Rectangle::~Rectangle()
	{
	}
};