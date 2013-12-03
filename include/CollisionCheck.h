#ifndef COLLISIONCHECK_H_
#define COLLISIONCHECK_H_

#include "Vector.h"

class Box;
class Circle;

class CollisionCheck
{
	static Vector xAxis, yAxis;
public:
	static bool collisionOccurred(const Box &b1, const Box &b2);
	static bool collisionOccurred(const Circle &c1, const Circle &c2);
};



#endif /* COLLISIONCHECK_H_ */
