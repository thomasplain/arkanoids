#ifndef PROJECTION_H
#define PROJECTION_H

class Circle;
class Vector;
class Box;

class Projection
{
	float start, end;
protected:
	void setStartAndEnd(float startPoint, float endPoint);
public:
	Projection(float startPoint, float endPoint)
	{
		setStartAndEnd(startPoint, endPoint);
	}

	Projection(Circle c, Vector axis);
	Projection(Box b, Vector axis);
	bool operator==(const Projection &p) const;
	bool operator!=(const Projection &p) const;

	bool OverlapsWith(const Projection &p) const;
};

#endif	// PROJECTION_H
