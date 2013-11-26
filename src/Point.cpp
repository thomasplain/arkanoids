#include "Point.h"
#include <cmath>

inline float degreesToRadians(float degrees)
{
	return degrees * 3.14159265359f / 180;
}

void Point::RotateAboutOrigin(float degrees)
{
	float radians = degreesToRadians(degrees);
	float rotatedX = x * cos(radians) - y * sin(radians);
	float rotatedY = x * sin(radians) + y * cos(radians);
	x = rotatedX;
	y = rotatedY;
}

Point& Point::operator=(const Point &p)
{
	x = p.x;
	y = p.y;
	return *this;
}
