#include "CollisionCheck.h"
#include "Vector.h"
#include "Projection.h"
#include "Box.h"
#include "Circle.h"
#include <memory>

Vector CollisionCheck::xAxis(1, 0);
Vector CollisionCheck::yAxis(0, 1);

bool CollisionCheck::collisionOccurred(const Box &b1, const Box &b2)
{
	return Projection(b1, xAxis).OverlapsWith(Projection(b2, xAxis)) &&
		Projection(b1, yAxis).OverlapsWith(Projection(b2, yAxis));
}

bool CollisionCheck::collisionOccurred(const Circle &c1, const Circle &c2)
{
	std::auto_ptr<Vector> separatingAxis(Vector(c1.GetCentre()) - Vector(c2.GetCentre()));
	return c1.Project(xAxis).OverlapsWith(c2.Project(xAxis)) &&
		c1.Project(yAxis).OverlapsWith(c2.Project(yAxis)) &&
		c1.Project(*separatingAxis).OverlapsWith(c2.Project(*separatingAxis));
}
