#ifndef CIRCLE_H
#define CIRCLE_H

class OrderedPair;
class Projection;
class Vector;
typedef float Radius;

#include "Shape.h"

class Circle : public Shape
{
	OrderedPair *centre;
	Radius radius;
	public:
		Circle(const OrderedPair& p, Radius r = 0);
		Circle(const Circle &c);
		Circle& operator=(const Circle &c);
		~Circle();
		void Translate(OrderedPair& translation);
		OrderedPair& GetCentre() const;
		Radius GetRadius() const;
		virtual Projection Project(const Vector& axis) const;
		OrderedPair* GetClosestPoint(const OrderedPair& op) const;
};

#endif /* CIRCLE_H */
