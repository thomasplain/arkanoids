#include "Circle.h"
#include "Point.h"
#include "Vector.h"
#include "OrderedPair.h"
#include "Projection.h"
#include <iostream>

Circle::Circle(const OrderedPair& p, Radius r)
{
	centre = new Point(p);
	radius = r;
}

Circle::Circle(const Circle& c)
{
	radius = c.radius;
	centre = new Point(*c.centre);
}

Circle& Circle::operator=(const Circle &c)
{
	delete centre;
	centre = new Point(*c.centre);
	radius = c.radius;

	return *this;
}

Circle::~Circle()
{
	delete centre;
}

void Circle::Translate(OrderedPair& translation)
{
	centre->TranslateBy(translation);
}

OrderedPair& Circle::GetCentre() const
{
	return *centre;
}

Radius Circle::GetRadius() const
{
	return radius;
}

Projection Circle::Project(const Vector& axis) const
{
	Vector centreVector(*centre);

	float centreProj = axis.Normalise().Dot(centreVector);
	float start = centreProj - radius;
	float end = centreProj + radius;

	return Projection(start, end);
}

const OrderedPair& Circle::GetClosestPoint(const OrderedPair& op)
{
	Vector distanceBetweenCentreAndPoint(Vector(op) - Vector(*centre));
	Vector normalisedDistance = distanceBetweenCentreAndPoint.Normalise();
	Vector pointOnCircumference = normalisedDistance.Times(radius);

	return Point(Vector(*centre) + pointOnCircumference);	
}
