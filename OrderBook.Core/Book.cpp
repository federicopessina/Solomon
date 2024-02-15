#include <iostream>
#include "Book.h"
#include "BookConsole.h"

Book::Book()
{

}

Book::~Book()
{
}

void Book::add(Order order)
{
	bool isBuyOrder = order.getIsBuy();
	
	m_bids.add(order);
}

void Book::cancel(std::string id)
{
	return;
}

int Book::getBidsSize()
{
	return 0;
}

int Book::getAsksSize()
{
	return 0;
}

int Book::getVolumeAtPrice(double price, bool isBid)
{
	return 0;
}

bool Book::match()
{
	return true;
}

void Book::place(Order& bid, Order& ask)
{
	BookConsole::place(bid, ask);
}