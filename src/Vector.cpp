#include "Vector.h"
#include <cmath>

float Vector::Length() const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

const Vector Vector::Normalise() const
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

const Vector& Vector::Subtract(const Vector& v)
{
	return Vector(x - v.x, y - v.y);
}

const Vector& Vector::Times(const float f)
{
	return Vector(x * f, y * f);
}

const Vector& Vector::operator+(const Vector& v)
{
	return Vector(this->Add(v));
}

const Vector& Vector::operator-(const Vector& v)
{
	return Vector(this->Subtract(v));
}
