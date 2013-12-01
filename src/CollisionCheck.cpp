#include "CollisionCheck.h"
#include "Vector.h"
#include "Projection.h"
#include "Box.h"

bool CollisionCheck::collisionOccurred(const Box &b1, const Box &b2)
{
	Vector xAxis(1, 0), yAxis(0, 1);

	return Projection(b1, xAxis).OverlapsWith(Projection(b2, xAxis)) &&
		Projection(b1, yAxis).OverlapsWith(Projection(b2, yAxis));
}
