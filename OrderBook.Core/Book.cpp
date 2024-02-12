#include "Book.h"
#include <iostream>

Book::Book()
{
}

Book::~Book()
{
}

void Book::add(Order order)
{
	if (order.getIsBuy())
	{
		m_bids.add(order);
	}
	else
	{
		m_asks.add(order);
	}
}

void Book::cancel(std::string id)
{

	return;
}

int Book::getVolumeAtPrice(double price, bool isBid)
{
	return 0;
}

Order Book::match(Order order)
{
	return Order();
}

void Book::place(Order order)
{
	std::cout << "id" << order.getId() << std::endl;
	// TODO Implement more.
}
