#include "AxisSet.h"
#include "OrderedPair.h"

int AxisSet::size() const
{
	return numAxes;
}

void AxisSet::add(const OrderedPair& op)
{
	delete axis;
	axis = new OrderedPair(op);
	numAxes = 1;
}

const OrderedPair& AxisSet::getAxis(int axisNum) const
{
	return *axis;
}
