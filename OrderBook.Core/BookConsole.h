#pragma once
#include "Order.h"
#include "AskStore.h"
#include "BidStore.h"

class BookConsole
{
public:
	BookConsole();
	~BookConsole();

	static void place(Order& bid, Order& ask);
private:

};

