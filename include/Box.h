#ifndef BOX_H_
#define BOX_H_

class OrderedPair;
class Projection;

#include "Shape.h"
#include "Vector.h"

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
	OrderedPair* GetClosestPoint(const OrderedPair& op) const;
	virtual int getNumVertices() const { return 4; };
	virtual Vector getVertex(int vertexNumber) const;
	virtual bool isVertex(const Vector& point) const { return false; };
};

#endif /* BOX_H_ */
