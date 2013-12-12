#ifndef BALL_H_
#define BALL_H_

#include "Vector.h"

class Ball
{
	int callCount;
	Vector position;
	Vector velocity;
	public:
	Ball() : callCount(0), position(0, 0) {};
	void setVelocity(Vector newVelocity);
	void updatePosition();
	Vector getPosition();
};


#endif // BALL_H_
