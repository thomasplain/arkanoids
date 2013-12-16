#include "Ball.h"
#include "Vector.h"

void Ball::setVelocity(Vector newVelocity)
{
	velocity = newVelocity;
}

void Ball::updatePosition(int currentTime)
{
	static int lastUpdateTime = 0;
	int deltaTimeMillis = currentTime - lastUpdateTime;
	float deltaTimeSecs = deltaTimeMillis / 1000.0;

	float newX = position.GetX() + (velocity.GetX() * deltaTimeSecs);
	float newY = position.GetY() + (velocity.GetY() * deltaTimeSecs);
	position = Vector(newX, newY);

	lastUpdateTime = currentTime;
}

Vector Ball::getPosition()
{
	return position;
}
