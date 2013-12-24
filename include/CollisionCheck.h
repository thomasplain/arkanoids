#ifndef COLLISIONCHECK_H_
#define COLLISIONCHECK_H_

class Shape;

class CollisionCheck
{
public:
	static bool collisionOccurred(const Shape &s1, const Shape &s2);
};



#endif /* COLLISIONCHECK_H_ */
