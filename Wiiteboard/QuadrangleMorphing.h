#ifndef QuadrangleMorphing
#include "Point.h"
#include "Rectangle.h"

class QuadrangleMorphing {
	QuadrangleMorphing(Rectangle quadrangle);
	~QuadrangleMorphing();
	double deformation(double x);
	double scaleX(double y);
	double scaleY(double x);
};

#endif