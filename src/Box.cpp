#include "Box.h"
#include "Point.h"
#include "Projection.h"
#include "Vector.h"
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

Projection Box::Project(const Vector& axis) const
{
	Vector firstVertex(*topLeftCorner);	

	Vector *secondVertex = firstVertex + Vector(0, -boxHeight),
		*thirdVertex = firstVertex + Vector(boxWidth, -boxHeight),
		*fourthVertex = firstVertex + Vector(boxWidth, 0);

	float firstVertexProj = axis.Normalise().Dot(firstVertex);
	float secondVertexProj = axis.Normalise().Dot(*secondVertex);
	float thirdVertexProj = axis.Normalise().Dot(*thirdVertex);
	float fourthVertexProj = axis.Normalise().Dot(*fourthVertex);

	float start = std::min(firstVertexProj, std::min(secondVertexProj, std::min(thirdVertexProj, fourthVertexProj)));
	float end = std::max(firstVertexProj, std::max(secondVertexProj, std::max(thirdVertexProj, fourthVertexProj)));

	delete secondVertex;
	delete thirdVertex;
	delete fourthVertex;

	return Projection(start, end);
}

OrderedPair* Box::GetClosestPoint(const OrderedPair& op)
{
	Vector *centre = Vector(*topLeftCorner) + Vector(boxWidth/2, -boxHeight/2);
	Vector *difference = Vector(op) - *centre;
	Vector offset;
	Vector *closest;
	float xValue = 0, yValue = 0; 

	if (fabs(difference->GetX()) >= boxWidth / 2 &&
		fabs(difference->GetY() >= boxHeight / 2))
	{
		xValue = (difference->GetX() > 0 ? 1 : -1) * boxWidth / 2;
		yValue = (difference->GetY() > 0 ? 1 : -1) * boxHeight / 2;
	}
	offset = Vector(xValue, yValue);
	closest = *centre + offset;
	delete centre, difference;
	return closest;
}
