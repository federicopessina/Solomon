#pragma once
#include <queue>
#include "Order.h"

struct PriceComparerLess
{
	bool operator()(const Order& lhs, const Order& rhs) const
	{
		double lhsPrice = lhs.getPrice(), rhsPrice = rhs.getPrice();

		if (lhsPrice < rhsPrice) return true;
		if (lhsPrice > rhsPrice) return false;
		if (lhs.getTimestamp() < rhs.getTimestamp()) return true;

		return false;
	}
};

class BidStore
{
private:
	std::priority_queue<Order, std::vector<Order>, PriceComparerLess> mOrders;

public:
	BidStore();
	~BidStore();

	void add(Order order);
	bool isEmpty();
	void removeTop();
	int size();
	Order top();
};

