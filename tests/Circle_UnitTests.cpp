#include "Circle.h"
#include "Box.h"
#include "Point.h"
#include "Projection.h"
#include "Vector.h"
#include "AxisSet.h"
#include "gtest/gtest.h"
#include <cmath>
#include <memory>
#include <iostream>

TEST(CircleTests, CentreInitialisedByConstructor)
{
	Circle c(Point(3, 2), 3);
	
	EXPECT_EQ(Point(3, 2), c.getCentre());
}

TEST(CircleTests, RadiusInitialisedByConstructor)
{
	Circle c(Point(0, 0), 4);
	
	EXPECT_EQ(4, c.GetRadius());
}

TEST(CircleTests, TranslateMovesCentre)
{
	Vector displacement(3, 3);
	
	Circle c(Point(0, 0), 1);
	
	c.Translate(displacement);
	
	EXPECT_EQ(Point(3, 3), c.getCentre());
}

TEST(CircleTests, OriginCentredProjectionIsSameOnAnyAxis)
{
	Circle c(Point(0, 0), 2);
	Vector axis(1, 0);
	Projection proj(-2, 2);

	EXPECT_EQ(proj, c.Project(axis));

	axis = Vector(1, 1);
	EXPECT_EQ(proj, c.Project(axis));

	axis = Vector(-2, 3);
	EXPECT_EQ(proj, c.Project(axis));

	axis = Vector(37, -49);
	EXPECT_EQ(proj, c.Project(axis));
}

TEST(CircleTests, ProjectionOnXAxisIsDiameter)
{
	Vector xAxis(1, 0);
	Circle c(Point(2, 2), 3);
	Projection expected(-1, 5);
	
	EXPECT_EQ(expected, c.Project(xAxis));
}

TEST(CircleTests, ProjectionOnYAxisIsDiameter)
{
	Vector yAxis(0, 1);
	Circle c(Point(3, 3), 3);
	Projection expected(0, 6);
	
	EXPECT_EQ(expected, c.Project(yAxis));
}

TEST(CircleTests, ProjectionOntoFortyFiveDegAxisIsDiameter)
{
	Vector fortyFiveAxis(1, 1);
	Circle c(Point(0, 3), 3);
	Projection expected((3 / sqrt(2)) - 3, (3 / sqrt(2)) + 3);

	EXPECT_EQ(expected, c.Project(fortyFiveAxis));
}

TEST(CircleTests, getClosestVertexReturnsPointOnCircumferenceIfOutside)
{
	Circle c(OrderedPair(0, 0), 2);
	OrderedPair p(0, 3);

	OrderedPair *closest = c.getClosestVertex(p);
	EXPECT_EQ(OrderedPair(0, 2), *closest);
	delete closest;

	p = OrderedPair(3, 0);
	closest = c.getClosestVertex(p);
	EXPECT_EQ(OrderedPair(2, 0), *closest);
	delete closest;

	p = OrderedPair(-3, 0);
	closest = c.getClosestVertex(p);
	EXPECT_EQ(OrderedPair(-2, 0), *closest);
	delete closest;
}

TEST(CircleTests, ClosestPointIsSelfIfInsideCircle)
{
	Circle c(Point(0, 0), 2);
	OrderedPair p(1, 0);

	OrderedPair *closest = c.getClosestVertex(p);
	EXPECT_EQ(p, *closest);
	delete closest;
}

TEST(CircleTests, NumberOfVerticesIsTwelveForNow)
{
	Circle c(Point(0, 0), 2);
	EXPECT_EQ(16, c.getNumVertices());
}

TEST(CircleTests, getVertexReturnsVerticesInEvenSteps)
{
	Circle c(Point(1, 1), 1);

	EXPECT_EQ(Point(2, 1), c.getVertex(0));
	EXPECT_EQ(Point(1.0 / sqrt(2) + 1, 1.0 / sqrt(2) + 1), c.getVertex(2));
	EXPECT_EQ(Point(0, 1), c.getVertex(8));
	EXPECT_EQ(Point(1 - 1.0 / sqrt(2), 1 - 1.0 / sqrt(2)), c.getVertex(10));
}

TEST(CircleTests, getVertexWrapsAround)
{
	Circle c(Point(1, 1), 1);

	EXPECT_EQ(Point(2, 1), c.getVertex(c.getNumVertices()));
	EXPECT_EQ(Point(0, 1), c.getVertex(c.getNumVertices() + 8));
}

TEST(CircleTests, PointsOnCircumferenceAreVertices)
{
	Circle c(Point(0, 0), 1);
	
	EXPECT_TRUE(c.isVertex(Point(1, 0)));
	EXPECT_TRUE(c.isVertex(Point(1.0 / sqrt(2), 1.0 / sqrt(2))));

	EXPECT_FALSE(c.isVertex(Point(90, 50)));
	EXPECT_FALSE(c.isVertex(Point(0, 0)));
}

TEST(CircleTests, NoSeparatingAxisWhenDirectlyAboveABox)
{
	Box b(Point(2, 2), 3, 3);
	Circle c(Point(3, 4), 1);

	std::auto_ptr<AxisSet> separatingAxes(c.getSeparatingAxes(&b));

	EXPECT_EQ(0, separatingAxes->size());
}

TEST(CircleTests, NoSeparatingAxisWhenDirectlyBesideABox)
{
	Box b(Point(2, 2), 3, 3);
	Circle c(Point(7, 1), 1);

	std::auto_ptr<AxisSet> separatingAxes(c.getSeparatingAxes(&b));

	EXPECT_EQ(0, separatingAxes->size());
}

TEST(CircleTests, ReturnsSeparatingAxisWhenInvertexVoronoiRegionOfBox)
{
	Box b(Point(1, 4), 2, 2);
	Circle c(Point(4, 5), 1);

	std::auto_ptr<AxisSet> separatingAxes(c.getSeparatingAxes(&b));

	EXPECT_EQ(1, separatingAxes->size());
	EXPECT_EQ(Point(1.0 / sqrt(2), 1.0 / sqrt(2)), separatingAxes->getAxis(0));
}
