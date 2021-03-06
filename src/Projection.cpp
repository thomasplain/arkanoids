#include "Projection.h"
#include "Vector.h"
#include "Box.h"
#include "Circle.h"
#include "Shape.h"
#include <algorithm>
#include <cmath>

const float tolerance = 0.00001;

void Projection::setStartAndEnd(float startPoint, float endPoint)
{
	start = std::min(startPoint, endPoint);
	end = std::max(startPoint, endPoint);
}

Projection::Projection(const Shape& s, Vector axis)
{
	*this = s.Project(axis);
}

bool Projection::operator==(const Projection &p) const
{
	return (fabs(start - p.start) < tolerance && 
			fabs(end - p.end) < tolerance);
}

bool Projection::operator!=(const Projection &p) const
{
	return !(*this == p);
}

bool Projection::OverlapsWith(const Projection &p) const
{
	if (p.end == p.start || end == start)
	{
		return (start > p.start && start < p.end) ||
			(p.start > start && p.start < end);
	}
	else
	{
		return (end > p.start && start < p.end) ||
			start < p.end && end > p.start;
	}
}
