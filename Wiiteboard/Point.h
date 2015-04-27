#pragma once
class Point {
public:
	Point();
	Point(double x, double y, double z);
	void setX(double x);
	double getX();
	void setY(double y);
	double getY();
	void setZ(double z);
	double getZ();
	~Point();
};

