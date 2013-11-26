#include "Box.h"
#include "Point.h"
#include <algorithm>
#include <cmath>
#include <iostream>

Box::Box(const OrderedPair& p, float width, float height) : boxWidth(width), boxHeight(height)
{
	topLeftCorner = new Point(p);
}

Box::Box(const OrderedPair &firstCorner, const OrderedPair &oppositeCorner)
{
	float top = std::max(firstCorner.GetY(), oppositeCorner.GetY());
	float left = std::min(firstCorner.GetX(), oppositeCorner.GetX());
	topLeftCorner = new Point(left, top);

	boxWidth = std::fabs(firstCorner.GetX() - oppositeCorner.GetX());
	boxHeight = std::fabs(firstCorner.GetY() - oppositeCorner.GetY());
}

Box::Box(const Box &b)
{
	this->boxHeight = b.boxHeight;
	this->boxWidth = b.boxWidth;

	this->topLeftCorner = new Point(*(b.topLeftCorner));
}

OrderedPair& Box::GetFirstVertex()
{
	return *topLeftCorner;
}

float Box::GetWidth() const
{
	return boxWidth;
}

float Box::GetHeight() const
{
	return boxHeight;
}
