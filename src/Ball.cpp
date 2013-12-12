#include "Ball.h"
#include "Vector.h"

void Ball::setVelocity(Vector newVelocity)
{
	velocity = newVelocity;
}

void Ball::updatePosition()
{
	float newX = position.GetX() + velocity.GetX();
	float newY = position.GetY() + velocity.GetY();
	position = Vector(newX, newY);
}

Vector Ball::getPosition()
{
	return position;
}
