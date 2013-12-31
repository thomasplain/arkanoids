#include "Line.h"
#include "Vector.h"
#include "Point.h"
#include "Projection.h"
#include "AxisSet.h"
#include <algorithm>
#include <cmath>

static bool floatEquals(float f1, float f2)
{
	return fabs(f1 - f2) < 0.00001 ? true : false;
}

Projection Line::Project(const Vector& axis) const
{
	float startProj = axis.Normalise().Dot(start);
	float endProj = axis.Normalise().Dot(end);

	return Projection(startProj, endProj);
}

Vector Line::getCentre() const
{
	return (Vector(start) * 0.5) + (Vector(end) * 0.5);
}

OrderedPair* Line::getClosestVertex(const OrderedPair& op) const
{
	float limitedX, limitedY;
	if (start.GetX() < end.GetX())
	{
		limitedX = std::max(start.GetX(), std::min(end.GetX(), op.GetX()));
	}
	else
	{
		limitedX = std::max(end.GetX(), std::min(start.GetX(), op.GetX()));
	}

	if (start.GetY() < end.GetY())
	{
		limitedY = std::max(start.GetY(), std::min(end.GetY(), op.GetY()));
	}
	else
	{
		limitedY = std::max(end.GetY(), std::min(start.GetY(), op.GetY()));
	}


	return new Point(limitedX, limitedY);
}

int Line::getNumVertices() const
{
	return 2;
}

Vector Line::getVertex(int vertexIndex) const
{
	return Vector(0, 0);
}

bool Line::isVertex(const OrderedPair& point) const
{
	if (point.GetX() >= start.GetX() && point.GetX() <= end.GetX())
	{
		float lineGradient = (end.GetX() - start.GetX()) /
			(end.GetY() - start.GetY());
		float offset = start.GetY() - lineGradient * start.GetX();

		float onLineYValue = point.GetX() * lineGradient + offset;

		return floatEquals(onLineYValue, point.GetY()) ? true : false;
	}
	else
	{
		return false;
	}
}

AxisSet* Line::getSeparatingAxes(const Shape* s) const
{
	AxisSet *as = new AxisSet();
	
	Vector parallelAxis = Vector(end) - Vector(start);
	Vector perpendicularAxis(-parallelAxis.GetY(), parallelAxis.GetX());

	as->add(parallelAxis.Normalise());
	as->add(perpendicularAxis.Normalise());

	return as;
}
