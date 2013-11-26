#include "gtest/gtest.h"
#include "Box.h"
#include "Point.h"

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
