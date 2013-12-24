#include "Circle.h"
#include "Point.h"
#include "Vector.h"
#include "OrderedPair.h"
#include "Projection.h"
#include "AxisSet.h"
#include <cmath>
#include <memory>

const float PI = 3.1415926535897;

Circle::Circle(const OrderedPair& p, float r)
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

Vector Circle::getCentre() const
{
	return *centre;
}

float Circle::GetRadius() const
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

OrderedPair* Circle::getClosestVertex(const OrderedPair& op) const
{
	Vector *closestPoint;

	Vector distanceBetweenCentreAndPoint(*(Vector(op) - Vector(*centre)));

	if (distanceBetweenCentreAndPoint.Length() > radius)
	{
		Vector normalisedDistance = distanceBetweenCentreAndPoint.Normalise();
		Vector *pointOnCircumference = normalisedDistance.Times(radius);
		closestPoint = Vector(*centre) + Vector(*pointOnCircumference);
		delete pointOnCircumference;
	}
	else
	{
		closestPoint = new Vector(op);
	}

	return closestPoint;
}

Vector Circle::getVertex(int vertexNumber) const
{
	float theta = (2 * PI / getNumVertices()) * vertexNumber;
	std::auto_ptr<Vector> vertex(new Vector(radius * std::cos(theta) + centre->GetX(), 		radius * std::sin(theta) + centre->GetY()));

	return *vertex;
}

bool Circle::isVertex(const OrderedPair& point) const
{
	std::auto_ptr<Vector> centreToPoint(Vector(point) - Vector(*centre));

	return (fabs(centreToPoint->Length() - radius) <= 0.00001);
}

AxisSet* Circle::getSeparatingAxes(const Shape* s)
{
	AxisSet *as =  new AxisSet();

	std::auto_ptr<OrderedPair> closestPoint(s->getClosestVertex(getCentre()));

	if (s->isVertex(*closestPoint))
	{
			std::auto_ptr<OrderedPair> closestPointToVertex(getClosestVertex(*closestPoint));
		Vector *separatingAxis = Vector(*closestPointToVertex)
				- Vector(*closestPoint);
		as->add(separatingAxis->Normalise());
		delete separatingAxis;
	}

	return as;
}
