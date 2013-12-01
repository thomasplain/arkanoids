#include "gtest/gtest.h"
#include "Box.h"
#include "Point.h"
#include "CollisionCheck.h"

TEST(CollisionCheckTests, DetectsNonCollisionBetweenTwoBoxesOnXAxis)
{
	Box b1(Point(0, 2), 2, 2), b2(Point(3, 2), 2, 2);

	ASSERT_FALSE(CollisionCheck::collisionOccurred(b1, b2));
}

TEST(CollisionCheckTests, DetectsCollisionBetweenTwoBoxesOnXAxis)
{
	Box b1(Point(0, 2), 2, 2), b2(Point(1, 2), 2, 2);

	ASSERT_TRUE(CollisionCheck::collisionOccurred(b1, b2));
}

TEST(CollisionCheckTests, DetectsNonCollisionBetweenTwoBoxesOnYAxis)
{
	Box b1(Point(0, 2), 2, 2), b2(Point(0, 5), 2, 2);
	
	ASSERT_FALSE(CollisionCheck::collisionOccurred(b1, b2));
}
