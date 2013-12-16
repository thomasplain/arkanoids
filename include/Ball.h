#ifndef BALL_H_
#define BALL_H_

#include "Vector.h"

class Ball
{
	Vector position;
	Vector velocity;
	public:
	Ball() : position(0, 0) {};
	void setVelocity(Vector newVelocity);
	void updatePosition(int currentTime);
	Vector getPosition();
};


#endif // BALL_H_
