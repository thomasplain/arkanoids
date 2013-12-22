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

void AxisSet::combineWith(const AxisSet& as)
{
	for (int asIndex = 0; asIndex < as.size(); asIndex++)
	{
		bool noMatchFound = true;
		int thisIndex = 0;
		while (noMatchFound && thisIndex < size())
		{
			noMatchFound = !(as.getAxis(asIndex) == getAxis(thisIndex));
			thisIndex++;
		}
		if (noMatchFound) add(as.getAxis(asIndex));
	}
}
