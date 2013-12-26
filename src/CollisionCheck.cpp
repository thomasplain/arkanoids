#include <iostream>
#include "CollisionCheck.h"
#include "Vector.h"
#include "Projection.h"
#include "Shape.h"
#include "AxisSet.h"
#include <memory>

bool CollisionCheck::collisionOccurred(const Shape &s1, const Shape &s2)
{
	bool collision = true;

	std::auto_ptr<AxisSet> shape1AxisSet(s1.getSeparatingAxes(&s2));
	std::auto_ptr<AxisSet> shape2AxisSet(s2.getSeparatingAxes(&s1));

	shape1AxisSet->combineWith(*shape2AxisSet);

	int axisIndex = 0;

	if (shape1AxisSet->size() == 0)
	{
		collision = false;
	}

	while (axisIndex < shape1AxisSet->size() &&
			collision)
	{
		collision = collision &&
			s1.Project(Vector(shape1AxisSet->getAxis(axisIndex))).OverlapsWith(s2.Project(Vector(shape1AxisSet->getAxis(axisIndex))));
		std::cout <<"Axis = ("<<shape1AxisSet->getAxis(axisIndex).GetX()<<", "<<shape1AxisSet->getAxis(axisIndex).GetY()<<")"<<std::endl;
		axisIndex++;
	}

	return collision;
}
