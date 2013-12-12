#include "gtest/gtest.h"
#include "Ball.h"
#include "Vector.h"

TEST(BallTests, UpdatePositionTranslatesByVelocity)
{
	Ball b;
	Vector velocity(1, 1);
	b.setVelocity(velocity);

	b.updatePosition();

	ASSERT_EQ(Vector(1, 1), b.getPosition());
	b.updatePosition();
	ASSERT_EQ(Vector(2, 2), b.getPosition());

	b.setVelocity(Vector(3, 4));
	b.updatePosition();

	ASSERT_EQ(Vector(5, 6), b.getPosition());
}
