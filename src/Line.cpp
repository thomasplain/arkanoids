#include "Line.h"
#include "Vector.h"
#include "Point.h"
#include "Projection.h"
#include "AxisSet.h"

Projection Line::Project(const Vector& axis) const
{
	float startProj = axis.Normalise().Dot(start);
	float endProj = axis.Normalise().Dot(end);

	return Projection(startProj, endProj);
}

Vector Line::getCentre() const
{
	std::auto_ptr<Vector> centre(Vector(start) - Vector(end));
	centre = centre->Times(0.5);
	centre = centre + Vector(start);

}

OrderedPair* Line::getClosestVertex(const OrderedPair& op) const
{
	return new Point(0,  0);
}

int Line::getNumVertices() const
{
	return 0;
}


Vector Line::getVertex(int vertexIndex) const
{
	return Vector(0, 0);
}

bool Line::isVertex(const OrderedPair& point) const
{
	return true;
}

AxisSet* Line::getSeparatingAxes(const Shape* s) const
{
	return new AxisSet();
}
