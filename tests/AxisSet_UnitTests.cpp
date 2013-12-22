#include "gtest/gtest.h"
#include "AxisSet.h"
#include "Point.h"

TEST(AxisSetTests, AxisSetInitialisedEmpty)
{
	AxisSet as;

	EXPECT_EQ(0, as.size());
}

TEST(AxisSetTests, AddAxisToAxisSet)
{
	AxisSet as;

	as.add(Point(1, 0));

	EXPECT_EQ(1, as.size());

	EXPECT_EQ(Point(1, 0), as.getAxis(0));
}

TEST(AxisSetTests, AddTwoAxesToAxisSet)
{
	AxisSet as;

	as.add(Point(1, 1));
	as.add(Point(2, 2));

	EXPECT_EQ(2, as.size());
	EXPECT_EQ(Point(1, 1), as.getAxis(0));
	EXPECT_EQ(Point(2, 2), as.getAxis(1));
}

TEST(AxisSetTests, RemoveAxisFromMiddleOfSet)
{

	AxisSet as;

	as.add(Point(1, 1));
	as.add(Point(3, 3));
	as.add(Point(2, 2));

	EXPECT_EQ(3, as.size());

	as.remove(1);

	EXPECT_EQ(2, as.size());
	EXPECT_EQ(Point(1, 1), as.getAxis(0));
	EXPECT_EQ(Point(2, 2), as.getAxis(1));
}
