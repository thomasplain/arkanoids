#include "gtest/gtest.h"
#include "Box.h"
#include "Circle.h"
#include "Point.h"
#include "CollisionCheck.h"
#include <cmath>

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

TEST(CollisionCheckTests, DetectsCollisionBetweenTwoBoxesOnYAxis)
{
	Box b1(Point(0, 2), 2, 2), b2(Point(0, 3), 2, 2);
	
	ASSERT_TRUE(CollisionCheck::collisionOccurred(b1, b2));
}

TEST(CollisionCheckTests, DetectsCollisionAtTwoBoxCorners)
{
	Box b1(Point(3, 4), 2, 1), b2(Point(4.9, 4.9), 1, 1);

	ASSERT_TRUE(CollisionCheck::collisionOccurred(b1, b2));

	b2 = Box(Point(2.1, 4.9), 1, 1);
	ASSERT_TRUE(CollisionCheck::collisionOccurred(b1, b2));

	b2 = Box(Point(2.1, 3.1), 1, 1);
	ASSERT_TRUE(CollisionCheck::collisionOccurred(b1, b2));
	
	b2 = Box(Point(4.9, 3.1), 1, 1);
	ASSERT_TRUE(CollisionCheck::collisionOccurred(b1, b2));
}

TEST(CollisionCheckTests, DetectsNonCollisionBetweenTwoCirclesOnXAxis)
{
	Circle c1(Point(0, 2), 1), c2(Point(2, 2), 1);

	ASSERT_FALSE(CollisionCheck::collisionOccurred(c1, c2));
}

TEST(CollisionCheckTests, DetectsCollisionBetweenTwoCirclesOnXAxis)
{
	Circle c1(Point(0, 2), 1), c2(Point(2, 2), 2);

	ASSERT_TRUE(CollisionCheck::collisionOccurred(c1, c2));
}

TEST(CollisionCheckTests, DetectsNonCollisionBetweenTwoCirclesOnYAxis)
{
	Circle c1(Point(0, 1), 1), c2(Point(0, 3), 1);

	ASSERT_FALSE(CollisionCheck::collisionOccurred(c1, c2));
}

TEST(CollisionCheckTests, DetectsCollisionBetweenTwoCirclesOnYAxis)
{
	Circle c1(Point(0, 2), 1), c2(Point(0, 3), 2);

	ASSERT_TRUE(CollisionCheck::collisionOccurred(c1, c2));
}

TEST(CollisionCheckTests, DetectsNonCollisionBetweenTwoCirclesOnFortyFiveDegAxis)
{
	Circle c1(Point(0, 0), 1), c2(Point(1 + 1/sqrt(2), 1 + 1/sqrt(2)), 1);
	
	ASSERT_FALSE(CollisionCheck::collisionOccurred(c1, c2));
}

TEST(CollisionCheckTests, DetectsCollisionBetweenTwoCirclesOnFortyFiveDegAxis)
{
	Circle c1(Point(0, 0), 1), c2(Point(1 + 1/sqrt(2), 1 + 1/sqrt(2)), 2);
	
	ASSERT_TRUE(CollisionCheck::collisionOccurred(c1, c2));
}

TEST(CollisionCheckTests, DetectsNonCollisionBetweenBoxAndCircleOnXAndYAxes)
{
	Circle c(Point(1, 1), 3); Box b(Point(1, 6), 2, 2);

	ASSERT_FALSE(CollisionCheck::collisionOccurred(c, b));

	b = Box(Point(5, 1), 2, 2);

	ASSERT_FALSE(CollisionCheck::collisionOccurred(c, b));
}

TEST(CollisionCheckTests, DetectsCollisionBetweenBoxAndCircleOnXAndYAxes)
{
	Circle c(Point(1, 1), 3); Box b(Point(1, 5), 2, 2);

	ASSERT_TRUE(CollisionCheck::collisionOccurred(c, b));

	b = Box(Point(3, 1), 2, 2);

	ASSERT_TRUE(CollisionCheck::collisionOccurred(c, b));
}

TEST(CollisionCheckTests, DetectsNonCollisionBetweenBoxAndCircleOnCorner)
{
	Box b(Point(-1, 1), 2, 2); Circle c(Point(1.9, 1.9), 1);

	ASSERT_FALSE(CollisionCheck::collisionOccurred(b, c));
}

TEST(CollisionCheckTests, DetectsCollisionBetweenBoxAndCircleOnCorner)
{
	Box b(Point(-1, 1), 2, 2); Circle c(Point(1.5, 1.5), 1);

	ASSERT_TRUE(CollisionCheck::collisionOccurred(b, c));
}
