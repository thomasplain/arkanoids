#ifndef SHAPE_H_
#define SHAPE_H_

class Projection;
class Vector;

class Shape
{
public:
	virtual Projection Project(const Vector& axis) const = 0;
	virtual Vector getCentre() const = 0;
	virtual int getNumVertices() const = 0;
	virtual Vector getVertex(int vertexIndex) const = 0;
	virtual bool isVertex(const OrderedPair& point) const = 0;
};

#endif // SHAPE_H_
