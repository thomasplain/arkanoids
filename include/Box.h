#ifndef BOX_H_
#define BOX_H_

class OrderedPair;
class Projection;
class AxisSet;

#include "Shape.h"

class Box : public Shape
{
	OrderedPair* corners[4];
	float boxWidth, boxHeight;
	void setCorners(const OrderedPair& topLeftCorner);
public:
	Box(const OrderedPair& p, float width, float height);
	Box(const OrderedPair& firstCorner, const OrderedPair &oppositeCorner);
	Box(const Box &b);
	const Box& operator=(const Box& b);
	~Box();
	float GetWidth() const;
	float GetHeight() const;
	virtual Projection Project(const Vector& axis) const;
	OrderedPair* GetClosestPoint(const OrderedPair& op) const;
	virtual int getNumVertices() const { return sizeof(corners)/sizeof(corners[0]); };
	virtual Vector getVertex(int vertexNumber) const;
	virtual bool isVertex(const OrderedPair& point) const;

	virtual AxisSet* getSeparatingAxes(const Shape&);
};

#endif /* BOX_H_ */
