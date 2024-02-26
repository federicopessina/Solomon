#pragma once

#include <string>
#include "Order.h"
#include "VolumeStore.h"
#include "BidStore.h"
#include "AskStore.h"

/// <summary>
/// Data structure that store the Orders.
/// </summary>
class Book
{
private:
	BidStore mBids;
	AskStore mAsks;

public:
	Book();
	~Book();

	void add(Order order);
	void cancel(std::string id);
	int getBidsSize();
	int getAsksSize();
	int getVolumeAtPrice(double price, bool isBid);
	void match();
	static void place(Order& ask, Order& bid);

};

