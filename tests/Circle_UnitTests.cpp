#include "Circle.h"
#include "Point.h"
#include "Projection.h"
#include "Vector.h"
#include "gtest/gtest.h"
#include <cmath>
#include <iostream>

TEST(CircleTests, CentreInitialisedByConstructor)
{
	Circle c(Point(3, 2), 3);
	
	EXPECT_EQ(Point(3, 2), c.GetCentre());
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
	
	EXPECT_EQ(Point(3, 3), c.GetCentre());
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

TEST(CircleTests, GetClosestPointReturnsPointOnCircumferenceIfOutside)
{
	Circle c(Point(0, 0), 2);
	Point p(0, 3);

	Point closest(c.GetClosestPoint(p));
	ASSERT_EQ(Point(0, 2), closest);

	p = Point(3, 0);
	closest = c.GetClosestPoint(p);
	ASSERT_EQ(Point(2, 0), closest);

	p = Point(-3, 0);
	closest = c.GetClosestPoint(p);
	ASSERT_EQ(Point(-2, 0), closest);
}

TEST(CircleTest, ClosestPointIsSekfIfInsideCircle)
{
	Circle c(Point(0, 0), 2);
	Point p(1, 0);

	Point closest(c.GetClosestPoint(p));
	ASSERT_EQ(p, closest);
}
