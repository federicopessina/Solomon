#pragma once

#include <string>
#include "Order.h"
#include "VolumeMap.h"


/// <summary>
/// Data structure that store the Orders.
/// </summary>
class Book
{
private:
	BidStore m_bids;

public:
	Book();
	~Book();

	void add(Order order);
	void cancel(std::string id);
	int getBidsSize();
	int getAsksSize();
	int getVolumeAtPrice(double price, bool isBid);
	bool match();
	static void place(Order& ask, Order& bid);

};

