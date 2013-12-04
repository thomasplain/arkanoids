#ifndef SHAPE_H_
#define SHAPE_H_

class Projection;
class Vector;

class Shape
{
public:
	virtual Projection Project(const Vector& axis) const = 0;
};

#endif // SHAPE_H_