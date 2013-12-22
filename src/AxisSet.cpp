#include "AxisSet.h"
#include "OrderedPair.h"

int AxisSet::size() const
{
	return axisList.size();
}

void AxisSet::add(const OrderedPair& op)
{
	axisList.push_back(op);
}

void AxisSet::remove(int axisNumToRemove)
{
	axisList.erase(axisList.begin() + axisNumToRemove);
}

const OrderedPair& AxisSet::getAxis(int axisNum) const
{
	return axisList[axisNum];
}
