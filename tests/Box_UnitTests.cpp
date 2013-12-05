#include "gtest/gtest.h"
#include "Box.h"
#include "Point.h"
#include "Projection.h"
#include "Vector.h"
#include <cmath>
#include <iostream>
#include <memory>

class BoxTests : public ::testing::Test
{
	Box *expected;
protected:
	BoxTests()
	{
		expected = new Box(Point(0, 0), 0, 0);
	}

	void compareBoxes(Box b)
	{
		ASSERT_EQ(b.GetFirstVertex(), expected->GetFirstVertex());
		ASSERT_EQ(b.GetWidth(), expected->GetWidth());
		ASSERT_EQ(b.GetHeight(), expected->GetHeight());
	}

	void expect(Box b)
	{
		delete expected;
		expected = new Box(b);
	}
};

TEST_F(BoxTests, InitialiseWithTopLeftCornerWidthAndHeight)
{
	Point p(4, 4);
	Box b(p, 3, 2);

	ASSERT_EQ(b.GetFirstVertex(), p);
	ASSERT_EQ(b.GetWidth(), 3);
	ASSERT_EQ(b.GetHeight(), 2);
}

TEST_F(BoxTests, InitialiseWithTwoOppositeCorners)
{
	Point topLeft(2, 2), bottomRight(4, 0);

	expect(Box(topLeft, 2, 2));
	Box b(topLeft, bottomRight);
	compareBoxes(b);

	b = Box(bottomRight, topLeft);
	compareBoxes(b);

	Point topRight(4, 2), bottomLeft(2, 0);
	b = Box(topRight, bottomLeft);
	compareBoxes(b);

	b = Box(bottomLeft, topRight);
	compareBoxes(b);
}

TEST_F(BoxTests, ProjectOntoXAxis)
{
	Projection p(-2, 2);
	Box b(Point(-2, 1), 4, 1);
	Vector xAxis(1, 0);

	EXPECT_EQ(p, b.Project(xAxis));	
}

TEST_F(BoxTests, ProjectOntoYAxis)
{
	Projection p(0, 1);
	Box b(Point(-2, 1), 4, 1);
	Vector yAxis(0, 1);

	EXPECT_EQ(p, b.Project(yAxis));	
}

TEST_F(BoxTests, ProjectOnto45DegAxis)
{
	Projection p(0, sqrt(2));
	Box b(Point(0, 1), 1, 1);
	Vector axis(1, 1);

	EXPECT_EQ(p, b.Project(axis));	

	p = Projection(-1/sqrt(2), 1/sqrt(2));
	axis = Vector(-1, 1);

	EXPECT_EQ(p, b.Project(axis));	
}

TEST_F(BoxTests, ClosestPointIsTopLeftCornerWhenInTopLeftRegion)
{
	Box b(OrderedPair(-1, 1), 2, 2);
	OrderedPair p(-2, 5);

	std::auto_ptr<OrderedPair> closest(b.GetClosestPoint(p));
	EXPECT_EQ(Point(-1, 1), *closest);
}

TEST_F(BoxTests, ClosestPointIsTopRightCornerWhenInTopRightRegion)
{
	Box b(OrderedPair(-1, 1), 2, 2);
	OrderedPair p(3, 4);

	std::auto_ptr<OrderedPair> closest(b.GetClosestPoint(p));
	EXPECT_EQ(OrderedPair(1, 1), *closest);
}
