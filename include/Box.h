#ifndef BOX_H_
#define BOX_H_

#include <string>

class OrderedPair;
class Projection;
class AxisSet;

#include "Shape.h"

class Box : public Shape
{
	OrderedPair* corners[4];
	float boxWidth, boxHeight;
	void setCorners(const OrderedPair& topLeftCorner);
	std::string findVoronoiRegion(const OrderedPair& op) const;
public:
	Box(const OrderedPair& p, float width, float height);
	Box(const OrderedPair& firstCorner, const OrderedPair &oppositeCorner);
	Box(const Box &b);
	const Box& operator=(const Box& b);
	~Box();

	float GetWidth() const;
	float GetHeight() const;
	virtual Projection Project(const Vector& axis) const;

	virtual	OrderedPair* getClosestVertex(const OrderedPair& op) const;
	virtual	Vector getCentre() const;

	virtual int getNumVertices() const { return sizeof(corners)/sizeof(corners[0]); };
	virtual Vector getVertex(int vertexNumber) const;
	virtual bool isVertex(const OrderedPair& point) const;

	virtual AxisSet* getSeparatingAxes(const Shape* other = 0) const;
};

#endif /* BOX_H_ */
