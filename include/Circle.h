#ifndef CIRCLE_H
#define CIRCLE_H

class OrderedPair;
class Projection;

#include "Shape.h"
#include "Vector.h"

class Circle : public Shape
{
	OrderedPair *centre;
	float radius;
	public:
		Circle(const OrderedPair& p, float r = 0);
		Circle(const Circle &c);
		Circle& operator=(const Circle &c);
		~Circle();
		void Translate(OrderedPair& translation);
		virtual Vector getCentre() const;
		float GetRadius() const;
		virtual Projection Project(const Vector& axis) const;
		virtual	OrderedPair* getClosestVertex(const OrderedPair& op) const;
		virtual int getNumVertices() const { return 16; };
		virtual Vector getVertex(int vertexNumber) const;
		virtual bool isVertex(const OrderedPair& point) const;
		virtual AxisSet* getSeparatingAxes(const Shape* s) const;
};

#endif /* CIRCLE_H */
