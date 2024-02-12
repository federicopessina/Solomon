#pragma once

#include <vector>
#include <queue>
#include "CompareOrder.cpp"
#include "Order.h"

class Store
{
public:
	Store();
	~Store();

	void 
	add(Order& order);
	//const std::priority_queue<Order, std::vector<Order>, Comparer>& get() const; // TODO Implement.
	Order get(std::string id);
	void remove(Order order);

	std::priority_queue<Order, std::vector<Order>, Comparer> m_orders; // TODO Make private.
private:
};

struct Comparer
{
public:
	bool operator()(Order& a, Order& b);
};