#include "Circle.h"
#include "Point.h"
#include "OrderedPair.h"

Circle::Circle(OrderedPair *p, Radius r)
{
	centre = new Point(*p);
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
