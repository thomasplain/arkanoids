#include "Projection.h"
#include "Vector.h"
#include "Box.h"
#include "Circle.h"
#include <algorithm>

void Projection::setStartAndEnd(float startPoint, float endPoint)
{
	start = std::min(startPoint, endPoint);
	end = std::max(startPoint, endPoint);
}

Projection::Projection(Circle c, Vector axis)
{
	Vector circleCentre(c.GetCentre().GetX(), c.GetCentre().GetY());
	Vector normalisedAxis = axis.Normalise();
	float projectionMidPoint = normalisedAxis.Dot(circleCentre);

	setStartAndEnd(projectionMidPoint - c.GetRadius(),
			projectionMidPoint + c.GetRadius());
}

Projection::Projection(Box b, Vector axis)
{
	*this = b.Project(axis);
}

bool Projection::operator==(const Projection &p) const
{
	return (start == p.start && end == p.end);
}

bool Projection::operator!=(const Projection &p) const
{
	return !(*this == p);
}

bool Projection::OverlapsWith(const Projection &p) const
{
	return (start > p.start && p.end > start) ||
			(end < p.end && p.start < end) ||
			(start < p.start && p.end < end) ||
			(start == p.start && p.end == end);
}
