#ifndef AXISSET_H_
#define AXISSET_H_

#include "OrderedPair.h"
#include <vector>

class AxisSet
{
	std::vector<OrderedPair> axisList;
	public:
		int size() const;
		void add(const OrderedPair& op);
		void remove(int axisNumToRemove);
		const OrderedPair& getAxis(int axisNum) const;
		void combineWith(const AxisSet& as);
};


#endif // AXISSET_H_
