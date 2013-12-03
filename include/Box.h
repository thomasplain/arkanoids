#ifndef BOX_H_
#define BOX_H_

class OrderedPair;
class Projection;
class Vector;

#include "Shape.h"

class Box : public Shape
{
	OrderedPair* topLeftCorner;
	float boxWidth, boxHeight;
public:
	Box(const OrderedPair& p, float width, float height);
	Box(const OrderedPair& firstCorner, const OrderedPair &oppositeCorner);
	Box(const Box &b);
	OrderedPair& GetFirstVertex();
	float GetWidth() const;
	float GetHeight() const;
	virtual Projection Project(const Vector& axis) const;
};

#endif /* BOX_H_ */
