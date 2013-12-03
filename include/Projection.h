#ifndef PROJECTION_H
#define PROJECTION_H

class Vector;
class Shape;

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

	Projection(const Shape& s, Vector axis);
	bool operator==(const Projection &p) const;
	bool operator!=(const Projection &p) const;

	bool OverlapsWith(const Projection &p) const;
};

#endif	// PROJECTION_H
