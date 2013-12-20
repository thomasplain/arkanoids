#include "Box.h"
#include "Point.h"
#include "Projection.h"
#include "Vector.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>

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

OrderedPair* Box::GetClosestPoint(const OrderedPair& op) const
{
	std::auto_ptr<Vector> centre(Vector(*topLeftCorner) + Vector(boxWidth/2, -boxHeight/2));
	std::auto_ptr<Vector> difference(Vector(op) - *centre);
	float xValue = difference->GetX(), yValue = difference->GetY(); 

	if (fabs(xValue) >= boxWidth / 2)
	{
		xValue = (xValue > 0 ? 1 : -1) * boxWidth / 2;
	}
	if (fabs(yValue) >= boxHeight / 2)
	{
		yValue = (yValue > 0 ? 1 : -1) * boxHeight / 2;
	}
	
	return *centre + Vector(xValue, yValue);
}

Vector Box::getVertex(int vertexNumber) const
{
	std::auto_ptr<Vector> vertex(new Vector(*topLeftCorner));
	switch (vertexNumber)
	{
		case 0:
			break;
		case 1:
			vertex = std::auto_ptr<Vector>(Vector(*topLeftCorner) + Vector(0, -boxHeight));
			break;
		case 2:
			vertex = std::auto_ptr<Vector>(Vector(*topLeftCorner) + Vector(boxWidth, -boxHeight));
			break;
		case 3:
			vertex = std::auto_ptr<Vector>(Vector(*topLeftCorner) + Vector(boxWidth, 0));
			break;
		default:
			break;
	}

	return *vertex;
}
