#include "stdafx.h"
#include "QuadrangleMorphing.h"
#include "Rectangle.h"
#include <vector>
#include <cmath>


class QuadrangleMorphing {

	private:
		Rectangle morphableQuadrangle;
		Rectangle finalSquare;
		std::vector<Rectangle> quadrangleHistory;

	QuadrangleMorphing::QuadrangleMorphing(Rectangle quadrangle) {
		this->morphableQuadrangle = quadrangle;
		this->quadrangleHistory.push_back(morphableQuadrangle);
	}

	double deformation(double x) {
		Point pointD = quadrangleHistory.at(2).getVector().at(3);
		return (x * (pointD.getY() / pointD.getX()));
	}

	double scaleX(double y) {
		Point pointC = quadrangleHistory.at(3).getVector().at(2);
		Point pointD = quadrangleHistory.at(3).getVector().at(3);
		return y * ((pointC.getX() - pointD.getX()) / pointC.getY()) + pointD.getX();
	}

	double scaleY(double x) {
		Point pointB = quadrangleHistory.at(3).getVector().at(1);
		Point pointC = quadrangleHistory.at(3).getVector().at(2);
		return x * ((pointC.getY() - pointB.getY()) / pointC.getX()) + pointB.getY();
	}

	void addQuadrangle(Rectangle rectangle) {
		this->quadrangleHistory.push_back(rectangle);
	}

	double getRotate() {
		Point pointB = quadrangleHistory.at(1).getVector().at(1);
		return (asin(pointB.getX()) / sqrt(pow(pointB.getX(), 2) + pow(pointB.getY(), 2)));
	}

	void startQuadrangleTransformation(Rectangle rectangle) {
		quadrangleHistory.push_back(rectangle);
		transformation(rectangle);
	}

	void startPointTransformation(Point point) {
		pointTransformation(point);
	}


	private: 
		void transformation(Rectangle rectangle) {
			Rectangle newRectangle = Rectangle();
			Point rectanglePointA = rectangle.getVector().at(0);
			Point aPoint = Point();
			for (int i = 0; i < 4; ++i) {
				aPoint.setX(rectangle.getVector().at(i).getX() - rectanglePointA.getX());
				aPoint.setY(rectangle.getVector().at(i).getY() - rectanglePointA.getY());
				newRectangle.addPoint(aPoint);
			}
			addQuadrangle(newRectangle);
			rotation(newRectangle);
		}

		void pointTransformation(Point point) {
			Rectangle rectangle = quadrangleHistory.at(0);
			Point newPoint = Point();
			newPoint.setX(point.getX() - rectangle.getVector().at(0).getX());
			newPoint.setY(point.getY() - rectangle.getVector().at(0).getY());
			pointRotation(newPoint);
		}

		void rotation(Rectangle rectangle) {
			Rectangle newRectangle = Rectangle();
			newRectangle.addPoint(Point(0,0,0));
			Point aPoint = Point();
			double rotate = getRotate();
			for (int i = 1; i < 4; ++i) {
				double x = rectangle.getVector().at(i).getX();
				double y = rectangle.getVector().at(i).getY();
				aPoint.setX(x * cos(rotate) - y * sin(rotate));
				aPoint.setY(y * cos(rotate) + x * sin(rotate));
				newRectangle.addPoint(aPoint);
			}
			addQuadrangle(newRectangle);
			deformation(newRectangle);
		}

		void pointRotation(Point point) {
			Point newPoint = Point();
			double rotate = getRotate();
			newPoint.setX(point.getX() * cos(rotate) - point.getY() * sin(rotate));
			newPoint.setY(point.getY() * cos(rotate) - point.getX() * sin(rotate));
			pointDeformation(newPoint);
			//(x(Z_T) cos(rotate) - y(Z_T) sin(rotate), y(Z_T) cos(rotate) + x(Z_T) sin(rotate))
		}

		void deformation(Rectangle rectangle) {
			Rectangle newRectangle = Rectangle();
			newRectangle.addPoint(Point(0, 0, 0));
			Point aPoint = Point();
			for (int i = 1; i < 4; ++i) {
				double x = rectangle.getVector().at(i).getX();
				double y = rectangle.getVector().at(i).getY();
				aPoint.setX(x);
				aPoint.setY(y - deformation(x));
				newRectangle.addPoint(aPoint);
			}
			addQuadrangle(newRectangle);
			normalisation(newRectangle);
		}

		void pointDeformation(Point point) {
			Point newPoint = Point();
			newPoint.setX(point.getX());
			newPoint.setY(point.getY() - deformation(point.getX()));
			pointNormalisation(newPoint);
		}

		void normalisation(Rectangle rectangle) {
			Rectangle newRectangle = Rectangle();
			newRectangle.addPoint(Point(0, 0, 0));
			Point aPoint = Point();
			for (int i = 1; i < 4; ++i) {
				double x = rectangle.getVector().at(i).getX();
				double y = rectangle.getVector().at(i).getY();
				aPoint.setX(x / scaleX(y));
				aPoint.setY(y / scaleY(x));
				newRectangle.addPoint(aPoint);
			}
			this->finalSquare = newRectangle;
			addQuadrangle(newRectangle);
		}

		void pointNormalisation(Point point) {
			Point newPoint = Point();
			newPoint.setX(point.getX() / scaleX(point.getY()));
			newPoint.setY(point.getY() / scaleY(point.getX()));
		}
	


	Rectangle getFinalSquare() {
		return this->finalSquare;
	}






	QuadrangleMorphing::~QuadrangleMorphing()
	{
	}
};