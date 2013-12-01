#ifndef POINT_H
#define POINT_H

#include "OrderedPair.h"

class Point : public OrderedPair
{
public:
	Point(float xValue = 0, float yValue = 0) : OrderedPair(xValue, yValue) {}
	Point(const OrderedPair &op) : OrderedPair(op) {}

	void RotateAboutOrigin(float degrees);

	Point& operator=(const Point &p);
};

#endif // POINT_H
