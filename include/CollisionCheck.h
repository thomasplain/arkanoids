#ifndef COLLISIONCHECK_H_
#define COLLISIONCHECK_H_

class Box;

class CollisionCheck
{
public:
	static bool collisionOccurred(const Box &b1, const Box &b2);
};



#endif /* COLLISIONCHECK_H_ */
