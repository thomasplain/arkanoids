#include "Box.h"
#include "Point.h"
#include "Projection.h"
#include "Vector.h"
#include "AxisSet.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>

class Regions
{
public:
	static std::string TopLeftCorner;
	static std::string LeftEdge;
	static std::string BottomLeftCorner;
	static std::string BottomEdge;
	static std::string BottomRightCorner;
	static std::string RightEdge;
	static std::string TopRightCorner;
	static std::string TopEdge;
	static bool isCorner(std::string voronoiRegion)
	{
		return voronoiRegion == TopLeftCorner ||
			voronoiRegion == TopRightCorner ||
			voronoiRegion == BottomLeftCorner ||
			voronoiRegion == BottomRightCorner;
	}
};

std::string Regions::TopLeftCorner = "TopLeftCorner";
std::string Regions::LeftEdge = "LeftEdge";
std::string Regions::BottomLeftCorner = "BottomLeftCorner";
std::string Regions::BottomEdge = "BottomEdge";
std::string Regions::BottomRightCorner = "BottomRightCorner";
std::string Regions::RightEdge = "RightEdge";
std::string Regions::TopRightCorner = "TopRightCorner";
std::string Regions::TopEdge = "TopEdge";

static bool floatEqual(float f1, float f2)
{
	return fabs(f1 - f2) < 0.000001;
}

std::string Box::findVoronoiRegion(const OrderedPair& op) const
{
	float xValue = op.GetX(); float yValue = op.GetY();
	// Draw two lines from corner to corner
	float firstSectorBoundaryY = -boxHeight / boxWidth * xValue;
	float secondSectorBoundaryY = boxHeight / boxWidth * xValue;

	// Does the point lie directly on any of the lines
	if (floatEqual(firstSectorBoundaryY, yValue) || floatEqual(secondSectorBoundaryY, yValue))
	{
		bool xGreaterThanZero = xValue > 0;
		bool yGreaterThanZero = yValue > 0;

		if (xGreaterThanZero && yGreaterThanZero)
		{
			return Regions::TopRightCorner;
		}
		else if (xGreaterThanZero && !yGreaterThanZero)
		{
			return Regions::BottomRightCorner;
		}
		else if (!xGreaterThanZero && yGreaterThanZero)
		{
			return Regions::TopLeftCorner;
		}
		// This also covers the case where the point is the centre
		else if (!xGreaterThanZero && !yGreaterThanZero)
		{
			return Regions::BottomLeftCorner;
		}
	}

	if (fabs(xValue) >= boxWidth / 2 || fabs(yValue) >= boxHeight / 2)
	{
		if (fabs(xValue) >= boxWidth / 2)
		{
			if (yValue <= -boxHeight / 2)
			{
				return Regions::BottomRightCorner;
			}
			else if (yValue >= boxHeight / 2)
			{
				return Regions::TopRightCorner;
			}
			else
			{
				return Regions::RightEdge;
			}
		}
		else if (fabs(xValue) <= -boxWidth / 2)
		{
			if (yValue <= -boxHeight / 2)
			{
				return Regions::BottomLeftCorner;
			}
			else if (yValue >= boxHeight / 2)
			{
				return Regions::TopLeftCorner;
			}
			else
			{
				return Regions::LeftEdge;
			}
		}
		else
		{

			if (yValue <= -boxHeight / 2)
			{
				return Regions::BottomEdge;
			}
			else if (yValue >= boxHeight / 2)
			{
				return Regions::TopEdge;
			}
		}
	
	}

	// Find which internal quadrant the point lies in
	if (yValue > firstSectorBoundaryY)	
	{
		if (yValue < secondSectorBoundaryY)
		{
			return Regions::RightEdge;
		}
		else
		{
			return Regions::TopEdge;
		}
	}
	else
	{
		if (yValue < secondSectorBoundaryY)
		{
			return Regions::BottomEdge;
		}
		else
		{
			return Regions::LeftEdge;
		}
	}
}

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
	corners[1] = new Vector(Vector(topLeftCorner) + Vector(0, -boxHeight));
	corners[2] = new Vector(Vector(topLeftCorner) + Vector(boxWidth, -boxHeight));
	corners[3] = new Vector(Vector(topLeftCorner) + Vector(boxWidth, 0));
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

OrderedPair* Box::getClosestVertex(const OrderedPair& op) const
{
	Vector centre = getCentre();
	Vector difference(Vector(op) - centre);
	float xValue = difference.GetX(), yValue = difference.GetY(); 
	
	std::string voronoiRegion = findVoronoiRegion(difference);

	if (Regions::isCorner(voronoiRegion))
	{
		xValue = (xValue > 0 ? 1 : -1) * boxWidth / 2;
		yValue = (yValue > 0 ? 1 : -1) * boxHeight / 2;

		return new Vector(centre + Vector(xValue, yValue));
	}
	else if (voronoiRegion == Regions::RightEdge)
	{
		return new Vector(centre + Vector(boxWidth / 2, yValue));
	}
	else if (voronoiRegion == Regions::TopEdge)
	{
		return new Vector(centre + Vector(xValue, boxHeight / 2));
	}
	else if (voronoiRegion == Regions::BottomEdge)
	{
		return new Vector(centre + Vector(xValue, -boxHeight / 2));
	}
	else if (voronoiRegion == Regions::LeftEdge)
	{
		return new Vector(centre + Vector(-boxWidth / 2, yValue));
	}
}

Vector Box::getCentre() const
{
	Vector centre(Vector(*corners[0]) + Vector(boxWidth / 2, -boxHeight / 2));

	return centre;
}

Vector Box::getVertex(int vertexNumber) const
{
	vertexNumber = vertexNumber % getNumVertices();
	return *corners[vertexNumber];
}

bool Box::isVertex(const OrderedPair& point) const
{
	int vertexNumber = 0;
	bool vertexFound = false;

	while (vertexNumber < getNumVertices() &&
					!vertexFound)
	{
		vertexFound = getVertex(vertexNumber) == point;
		vertexNumber++;
	}

	return vertexFound;
}

AxisSet* Box::getSeparatingAxes(const Shape* other) const
{
	AxisSet* as = new AxisSet();
	
	Vector axis1(Vector(*corners[3]) - Vector(*corners[0]));
	Vector axis2(Vector(*corners[0]) - Vector(*corners[1]));

	as->add(axis1.Normalise()); as->add(axis2.Normalise());

	return as;
}
