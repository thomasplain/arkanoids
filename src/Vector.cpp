#include "Vector.h"
#include <cmath>

float Vector::Length()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

const Vector Vector::Normalise()
{
	float magnitude = Length();
	return Vector((x / magnitude), (y / magnitude));
}

float Vector::Dot(const Vector &v) const
{
	return ((this->x * v.x) + (this->y * v.y));
}

const Vector& Vector::Add(const Vector& v)
{
	return Vector(x + v.x, y + v.y);
}

const Vector& Vector::operator+(const Vector& v)
{
	return Vector(this->Add(v));
}
