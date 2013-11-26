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
	Vector firstVertex(b.GetFirstVertex()),
			secondVertex(firstVertex.GetX(), firstVertex.GetY() - b.GetHeight()),
			thirdVertex(secondVertex.GetX() + b.GetWidth(), firstVertex.GetY()),
			fourthVertex(firstVertex.GetX() + b.GetWidth(), firstVertex.GetY());

	float firstVertexProj = axis.Normalise().Dot(Vector(firstVertex.GetX(), firstVertex.GetY()));
	float secondVertexProj = axis.Normalise().Dot(Vector(secondVertex.GetX(), secondVertex.GetY()));
	float thirdVertexProj = axis.Normalise().Dot(Vector(thirdVertex.GetX(), thirdVertex.GetY()));
	float fourthVertexProj = axis.Normalise().Dot(Vector(fourthVertex.GetX(), fourthVertex.GetY()));

	start = std::min(firstVertexProj, std::min(secondVertexProj, std::min(thirdVertexProj, fourthVertexProj)));
	end = std::max(firstVertexProj, std::max(secondVertexProj, std::max(thirdVertexProj, fourthVertexProj)));
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
			(start < p.start && p.end < end);
}
