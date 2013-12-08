#ifndef VECTOR_H_
#define VECTOR_H_

#include "OrderedPair.h"

class Vector : public OrderedPair
{
public:
	Vector(float xValue = 1, float yValue = 0) : OrderedPair(xValue, yValue) {}
	Vector(const OrderedPair &v) : OrderedPair(v.GetX(), v.GetY()) {}

	float Length() const;
	const Vector Normalise() const;
	float Dot(const Vector &v) const;
	Vector* Add(const Vector& v);
	Vector* Subtract(const Vector& v);
	Vector* Times(const float f);

	Vector* operator+(const Vector& v);
	Vector* operator-(const Vector& v);
};

#endif /* VECTOR_H_ */
