#pragma once

#include <string>
#include "Order.h"
#include "Store.h"
#include "Map.h"

/// <summary>
/// Data structure that store the Orders.
/// </summary>
class Book
{
public:
	Book();
	~Book();

	/// <summary>
	/// Takes an order object and either fill it or places it in the limit book.
	/// </summary>
	/// <param name="order"></param>
	void Book::add(Order order);
	/// <summary>
	/// Cancel an order if it has not yet been filled, otherwise is a no-op.
	/// </summary>
	/// <param name="id"></param>
	void Book::cancel(std::string id);
	/// <summary>
	/// Get volume of open order for either buying or selling side of order book.
	/// </summary>
	/// <param name="price"></param>
	/// <param name="isBid"></param>
	/// <returns></returns>
	int Book::getVolumeAtPrice(double price, bool isBid);
	Order match(Order order);
	void place(Order order);

private:
	Store m_bids;
	Store m_asks;
	Map map;
};
