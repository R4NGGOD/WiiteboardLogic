#pragma once

class Rectangle
{
public:
	Rectangle();
	~Rectangle();
	bool fillVector(std::vector<Point> vector);
	void addPoint(Point point);
	std::vector<Point> getVector();
	bool isInsideOf(Point point);
};

