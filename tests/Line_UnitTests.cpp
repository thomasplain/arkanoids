#include "gtest/gtest.h"
#include "Line.h"
#include "Point.h"
#include "Vector.h"
#include "Projection.h"

TEST(LineTests, LineProjectsToSinglePoint)
{
	Line l(Point(0, -3), Point(0, 3));

	EXPECT_EQ(Projection(0, 0), l.Project(Vector(1, 0))); 
}

TEST(LineTests, LineProjectsToLine)
{
	Line l(Point(0, -3), Point(0, 3));

	EXPECT_EQ(Projection(-3, 3), l.Project(Vector(0, 1)));
}

TEST(LineTests, CentreOfLineIsMidPoint)
{
	Line l(Point(2, 4), Point(2, -4));

	EXPECT_EQ(Vector(2, 0), l.getCentre());

	Line l2(Point(-1, 0), Point(1, 2));

	EXPECT_EQ(Vector(0, 1), l2.getCentre());
}
