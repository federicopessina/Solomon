#pragma once
#include <queue>
#include "Order.h"

struct PriceComparerMore
{
	bool operator()(const Order& lhs, const Order& rhs) const
	{
		double lhsPrice = lhs.getPrice(), rhsPrice = rhs.getPrice();
		
		if (lhsPrice > rhsPrice) return true;
		if (lhsPrice < rhsPrice) return false;
		if (lhs.getTimestamp() < rhs.getTimestamp()) return true;

		return false;
	}
};

class AskStore
{
private:
	std::priority_queue<Order, std::vector<Order>, PriceComparerMore> mOrders;

public:
	AskStore();
	~AskStore();

	void add(Order order);
	bool isEmpty();
	void removeTop();
	int size();
	Order top();
};

