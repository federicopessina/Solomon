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
	/// Get store read-only.
	/// </summary>
	/// <returns></returns>
	std::vector<Order> get() const;
	/// <summary>
	/// Add element to store.
	/// </summary>
	/// <param name="order"></param>
	/// <see href="https://en.cppreference.com/w/cpp/algorithm/push_heap">cppreference</see>
	void add(Order order);
	//void remove(Order order);

private:
	std::vector<Order> m_orders;
};