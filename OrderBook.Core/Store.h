#pragma once

#include <vector>
#include "Order.h"

class Store
{
public:
	/// <summary>
	/// Constructor that heapifies the vector field.
	/// </summary>
	Store();
	~Store();

	/// <summary>
	/// Add element to store.
	/// </summary>
	/// <param name="order"></param>
	/// <see href="https://en.cppreference.com/w/cpp/algorithm/push_heap">cppreference</see>
	void add(Order order);
	std::vector<Order> get();
	//void remove(Order order);

private:
	std::vector<Order> m_orders;
};