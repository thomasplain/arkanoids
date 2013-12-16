#include "gtest/gtest.h"
#include "Ball.h"
#include "Vector.h"

TEST(BallTests, UpdatePositionTranslatesByVelocity)
{
	Ball b;
	Vector velocity(1, 1);
	b.setVelocity(velocity);

	b.updatePosition(1000);

	ASSERT_EQ(Vector(1, 1), b.getPosition());
	b.updatePosition(2000);
	ASSERT_EQ(Vector(2, 2), b.getPosition());

	b.setVelocity(Vector(3, 4));
	b.updatePosition(3000);

	ASSERT_EQ(Vector(5, 6), b.getPosition());
}
