#pragma once
#include <queue>
#include "Order.h"

struct PriceComparerLess
{
	bool operator()(const Order& lhs, const Order& rhs) const
	{
		return lhs.getPrice() < rhs.getPrice();
	}
};

class BidStore
{
private:
	std::priority_queue<Order, std::vector<Order>, PriceComparerLess> m_orders;

public:
	BidStore();
	~BidStore();

	void add(Order order);
	bool isEmpty();
	int size();
	Order top();
};

