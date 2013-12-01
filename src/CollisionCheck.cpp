#include "CollisionCheck.h"
#include "Vector.h"
#include "Projection.h"
#include "Box.h"

bool CollisionCheck::collisionOccurred(const Box &b1, const Box &b2)
{
	Vector xAxis(1, 0);

	return Projection(b1, xAxis).OverlapsWith(Projection(b2, xAxis));
}
