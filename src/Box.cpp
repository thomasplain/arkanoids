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
	setCorners(p);
}

Box::Box(const OrderedPair &firstCorner, const OrderedPair &oppositeCorner)
{
	boxWidth = std::fabs(firstCorner.GetX() - oppositeCorner.GetX());
	boxHeight = std::fabs(firstCorner.GetY() - oppositeCorner.GetY());

	float top = std::max(firstCorner.GetY(), oppositeCorner.GetY());
	float left = std::min(firstCorner.GetX(), oppositeCorner.GetX());
	
	setCorners(Point(left, top));
}

Box::Box(const Box &b)
{
	this->boxHeight = b.boxHeight;
	this->boxWidth = b.boxWidth;
	
	setCorners(b.getVertex(0));
}

const Box& Box::operator=(const Box& b)
{
	this->boxHeight = b.boxHeight;
	this->boxWidth = b.boxWidth;

	setCorners(b.getVertex(0));

	return *this;
}

Box::~Box()
{
	delete corners[0];
	delete corners[1];
	delete corners[2];
	delete corners[3];
}

void Box::setCorners(const OrderedPair& topLeftCorner)
{
	corners[0] = new Vector(topLeftCorner);
	corners[1] = Vector(topLeftCorner) + Vector(0, -boxHeight);
	corners[2] = Vector(topLeftCorner) + Vector(boxWidth, -boxHeight);
	corners[3] = Vector(topLeftCorner) + Vector(boxWidth, 0);
}

const OrderedPair& Box::GetFirstVertex()
{
	return getVertex(0);
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
	float firstVertexProj = axis.Normalise().Dot(getVertex(0));
	float secondVertexProj = axis.Normalise().Dot(getVertex(1));
	float thirdVertexProj = axis.Normalise().Dot(getVertex(2));
	float fourthVertexProj = axis.Normalise().Dot(getVertex(3));

	float start = std::min(firstVertexProj, std::min(secondVertexProj, std::min(thirdVertexProj, fourthVertexProj)));
	float end = std::max(firstVertexProj, std::max(secondVertexProj, std::max(thirdVertexProj, fourthVertexProj)));

	return Projection(start, end);
}

OrderedPair* Box::GetClosestPoint(const OrderedPair& op) const
{
	std::auto_ptr<Vector> centre(Vector(getVertex(0)) + Vector(boxWidth/2, -boxHeight/2));
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
	vertexNumber = vertexNumber % getNumVertices();
	return *corners[vertexNumber];
}
