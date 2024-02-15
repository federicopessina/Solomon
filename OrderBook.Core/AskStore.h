#pragma once
#include <queue>
#include "Order.h"

struct PriceComparerMore
{
	bool operator()(const Order& lhs, const Order& rhs) const
	{
		return lhs.getPrice() > rhs.getPrice();
	}
};

class AskStore
{
public:
	AskStore();
	~AskStore();

	void add(Order order);
	bool isEmpty();
	int size();
	Order top();
private:
	std::priority_queue<Order, std::vector<Order>, PriceComparerMore> m_orders;
};

