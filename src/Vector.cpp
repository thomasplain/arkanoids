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

Vector* Vector::Add(const Vector& v)
{
	return new Vector(x + v.x, y + v.y);
}

Vector* Vector::Subtract(const Vector& v)
{
	return new Vector(x - v.x, y - v.y);
}

Vector* Vector::Times(const float f)
{
	return new Vector(x * f, y * f);
}

Vector* Vector::operator+(const Vector& v)
{
	return this->Add(v);
}

Vector* Vector::operator-(const Vector& v)
{
	return this->Subtract(v);
}

Vector Vector::operator-()
{
	this->x = -(this->x);
	this->y = -(this->y);
	
	return *this;
}
