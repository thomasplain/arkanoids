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
		OrderedPair& GetCentre() const;
		float GetRadius() const;
		virtual Projection Project(const Vector& axis) const;
		OrderedPair* GetClosestPoint(const OrderedPair& op) const;
		virtual int getNumVertices() const { return 16; };
		virtual Vector getVertex(int vertexNumber) const;
		virtual bool isVertex(const Vector& point) const { return false; };
};

#endif /* CIRCLE_H */
