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

bool CollisionCheck::collisionOccurred(const Circle &c, const Box &b)
{
	bool collision = c.Project(yAxis).OverlapsWith(b.Project(yAxis)) &&
		c.Project(xAxis).OverlapsWith(b.Project(xAxis));
	if (collision)
	{
		std::auto_ptr<OrderedPair> closestPointOnBox(b.GetClosestPoint(c.GetCentre()));
		std::auto_ptr<OrderedPair> closestPointOnCircle(c.GetClosestPoint(*closestPointOnBox));
		if (*closestPointOnBox == *closestPointOnCircle) return collision;
		std::auto_ptr<Vector> separatingAxis(Vector(*closestPointOnBox) - Vector(*closestPointOnCircle));
		collision = collision && c.Project(*separatingAxis).OverlapsWith(b.Project(*separatingAxis));
	}

	return collision;
}

bool CollisionCheck::collisionOccurred(const Box &b, const Circle &c)
{
	return collisionOccurred(c, b);
}
