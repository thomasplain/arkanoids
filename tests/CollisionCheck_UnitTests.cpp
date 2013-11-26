#include "gtest/gtest.h"
#include "Box.h"
#include "Point.h"

TEST(CollisionCheckTests, DetectsCollisionBetweenTwoBoxesOnXAxis)
{
	Box b1(Point(0, 2), 2, 2), b2(Point(3, 2), 2, 2);

	ASSERT_FALSE(CollisionCheck::haveCollided(b1, b2));
}
