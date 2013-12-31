#include "Vector.h"
#include <cmath>

float Vector::Length() const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

const Vector Vector::Normalise() const
{
	float magnitude = Length();
	magnitude = fabs(magnitude - 0) < 0.000001 ? 1 : magnitude;
	return Vector((x / magnitude), (y / magnitude));
}

float Vector::Dot(const Vector &v) const
{
	return ((this->x * v.x) + (this->y * v.y));
}

Vector Vector::add(const Vector& v)
{
	return Vector(x + v.x, y + v.y);
}

Vector Vector::subtract(const Vector& v)
{
	return Vector(x - v.x, y - v.y);
}

Vector Vector::times(const float f)
{
	return Vector(x * f, y * f);
}

Vector Vector::operator+(const Vector& v)
{
	return this->add(v);
}

Vector Vector::operator*(const float f)
{
	return this->times(f);
}

Vector Vector::operator-(const Vector& v)
{
	return this->subtract(v);
}

Vector Vector::operator-()
{
	this->x = -(this->x);
	this->y = -(this->y);
	
	return *this;
}
