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

Projection Box::Project(const OrderedPair& axis)
{
//	return Projection(-2, 2);

	Vector secondVertex(topLeftCorner, firstVertex.GetY() - b.GetHeight()),
			thirdVertex(secondVertex.GetX() + b.GetWidth(), firstVertex.GetY()),
			fourthVertex(firstVertex.GetX() + b.GetWidth(), firstVertex.GetY());

	float firstVertexProj = axis.Normalise().Dot(Vector(firstVertex.GetX(), firstVertex.GetY()));
	float secondVertexProj = axis.Normalise().Dot(Vector(secondVertex.GetX(), secondVertex.GetY()));
	float thirdVertexProj = axis.Normalise().Dot(Vector(thirdVertex.GetX(), thirdVertex.GetY()));
	float fourthVertexProj = axis.Normalise().Dot(Vector(fourthVertex.GetX(), fourthVertex.GetY()));

	start = std::min(firstVertexProj, std::min(secondVertexProj, std::min(thirdVertexProj, fourthVertexProj)));
	end = std::max(firstVertexProj, std::max(secondVertexProj, std::max(thirdVertexProj, fourthVertexProj)));
}
