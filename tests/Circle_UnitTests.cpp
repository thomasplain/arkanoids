#include "Circle.h"
#include "Point.h"
#include "Projection.h"
#include "Vector.h"
#include "gtest/gtest.h"
#include <cmath>
#include <iostream>

TEST(CircleTests, CentreInitialisedByConstructor)
{
	Point p(3, 2);
	Circle c(p, 3);
	
	EXPECT_EQ(Point(3, 2), c.GetCentre());
}

TEST(CircleTests, RadiusInitialisedByConstructor)
{
	Point p(0, 0);
	Circle c(p, 4);
	
	EXPECT_EQ(4, c.GetRadius());
}

TEST(CircleTests, TranslateMovesCentre)
{
	Point p(0, 0);
	Vector displacement(3, 3);
	
	Circle c(p, 1);
	
	c.Translate(displacement);
	
	EXPECT_EQ(Point(3, 3), c.GetCentre());
}

TEST(CircleTests, OriginCentredProjectionIsSameOnAnyAxis)
{
	Point p(0, 0);
	Circle c(p, 2);
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
	Point centre(2, 2);
	Circle c(centre, 3);
	Projection expected(-1, 5);
	
	EXPECT_EQ(expected, c.Project(xAxis));
}

TEST(CircleTests, ProjectionOnYAxisIsDiameter)
{
	Vector yAxis(0, 1);
	Point centre(3, 3);
	Circle c(centre, 3);
	Projection expected(0, 6);
	
	EXPECT_EQ(expected, c.Project(yAxis));
}

TEST(CircleTests, ProjectionOntoFortyFiveDegAxisIsDiameter)
{
	Vector fortyFiveAxis(1, 1);
	Point centre(0, 3);
	Circle c(centre, 3);
	Projection expected((3 / sqrt(2)) - 3, (3 / sqrt(2)) + 3);

	EXPECT_EQ(expected, c.Project(fortyFiveAxis));
}
