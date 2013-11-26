#include "Circle.h"
#include "Point.h"
#include "gtest/gtest.h"

typedef Point Vector;

TEST(CircleTests, CentreInitialisedByConstructor)
{
	Point p(3, 2);
	Circle c(&p, 3);
	
	EXPECT_EQ(Point(3, 2), c.GetCentre());
}

TEST(CircleTests, RadiusInitialisedByConstructor)
{
	Point p(0, 0);
	Circle c(&p, 4);
	
	EXPECT_EQ(4, c.GetRadius());
}

TEST(CircleTests, TranslateMovesCentre)
{
	Point p(0, 0);
	Vector displacement(3, 3);
	
	Circle c(&p, 1);
	
	c.Translate(displacement);
	
	EXPECT_EQ(Point(3, 3), c.GetCentre());
}
