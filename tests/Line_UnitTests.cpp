#include "gtest/gtest.h"
#include "Line.h"
#include "Point.h"
#include "Vector.h"
#include "Projection.h"
#include "AxisSet.h"
#include <memory>

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

TEST(LineTests, ClosestVertexIsClosestPointOnLine)
{
	Line l(Point(2, 17), Point(2, 5));

	std::auto_ptr<OrderedPair> closest(l.getClosestVertex(Point(4, 7)));
	EXPECT_EQ(Vector(2, 7), *closest);

	closest = std::auto_ptr<OrderedPair>(l.getClosestVertex(Point(3, 20)));
	EXPECT_EQ(Vector(2, 17), *closest);

	closest = std::auto_ptr<OrderedPair>(l.getClosestVertex(Point(-3, -5)));
	EXPECT_EQ(Vector(2, 5), *closest);
}

TEST(LineTests, TwoVertices)
{
	Line l(Point(0, 0), Point(1, 1));
	EXPECT_EQ(2, l.getNumVertices());
}

TEST(LineTests, SeparatingAxesAreParallelAndPerpendicularToLine)
{
	Line l(Point(-1, -1), Point(1, 1));

	std::auto_ptr<AxisSet> as(l.getSeparatingAxes());

	EXPECT_EQ(2, as->size());

	EXPECT_EQ(Vector(1.0/sqrt(2), 1.0/sqrt(2)), as->getAxis(0));
}

TEST(LineTests, AnyPointOnLineIsAVertex)
{
	Line l(Point(-1, -1), Point(1, 1));

	EXPECT_TRUE(l.isVertex(Point(-1, -1)));
	EXPECT_FALSE(l.isVertex(Point(-2, -1)));

	EXPECT_TRUE(l.isVertex(Point(0, 0)));

	EXPECT_TRUE(l.isVertex(Point(1.0/sqrt(2), 1.0/sqrt(2))));

	EXPECT_FALSE(l.isVertex(Point(2, 2)));
}
