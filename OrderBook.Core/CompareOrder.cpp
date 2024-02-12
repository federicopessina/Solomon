#include "Order.h"

class CompareOrder {
public:
	bool operator()(Order& o1, Order& o2)
	{
		if (o1.getPrice() < o2.getPrice())
			return true;

		if (o1.getPrice() == o2.getPrice() && o1.getTimestamp() <= o2.getTimestamp())
			return true;

		return false;
	}
};