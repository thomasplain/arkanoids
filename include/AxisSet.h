#ifndef AXISSET_H_
#define AXISSET_H_

#include "OrderedPair.h"

class AxisSet
{
	OrderedPair *axis;
	int numAxes;
	public:
		AxisSet()
		{
			axis = new OrderedPair(0, 0);
			numAxes = 0;
		}
		AxisSet(const AxisSet& as)
		{
			axis = new OrderedPair(*as.axis);
		}
		const AxisSet& operator=(const AxisSet& as)
		{
			axis = new OrderedPair(*as.axis);
			return *this;
		}
		~AxisSet()
		{
			delete axis;
		}
		int size() const;
		void add(const OrderedPair& op);
		const OrderedPair& getAxis(int axisNum) const;
};


#endif // AXISSET_H_
