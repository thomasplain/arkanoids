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
