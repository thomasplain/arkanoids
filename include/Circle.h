#ifndef CIRCLE_H
#define CIRCLE_H

class OrderedPair;
class Projection;
class Vector;
typedef float Radius;

class Circle
{
	OrderedPair *centre;
	Radius radius;
	public:
		Circle(OrderedPair *p, Radius r = 0);
		Circle(const Circle &c);
		Circle& operator=(const Circle &c);
		~Circle();
		void Translate(OrderedPair& translation);
		OrderedPair& GetCentre() const;
		Radius GetRadius() const;
		Projection Project(const Vector axis);
};

#endif /* CIRCLE_H */
