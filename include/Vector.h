#ifndef VECTOR_H_
#define VECTOR_H_

#include "OrderedPair.h"

class Vector : public OrderedPair
{
public:
	Vector(float xValue = 1, float yValue = 0) : OrderedPair(xValue, yValue) {}
	Vector(const OrderedPair &v) : OrderedPair(v.GetX(), v.GetY()) {}

	float Length();
	const Vector Normalise();
	float Dot(const Vector &v) const;
};

#endif /* VECTOR_H_ */
