#include <iostream>
#include "Book.h"
#include "BookConsole.h"

Book::Book() 
{ 

}

Book::~Book() { }

void Book::add(Order order)
{
	if (order.getIsBuy())
	{
		m_bids_.add(order);
	}
	else
	{
		m_asks_.add(order);
	}
}

void Book::cancel(std::string id)
{
	return;
}

int Book::getBidsSize()
{
	return m_bids_.size();
}

int Book::getAsksSize()
{
	return m_asks_.size();
}

int Book::getVolumeAtPrice(double price, bool isBid)
{
	return 0;
}

void Book::match()
{
	if (m_bids_.isEmpty() || m_asks_.isEmpty())
		return;

	Order topBid = m_bids_.top(), topAsk = m_asks_.top();
	int topBidVolume = topBid.getVolume(), topAskVolume = topAsk.getVolume();

	if (topBid.getPrice() >= topAsk.getPrice())
	{
		place(topBid, topAsk);

		m_bids_.removeTop();
		m_asks_.removeTop();

		match();
	}

	return;
}

void Book::place(Order& bid, Order& ask)
{
	BookConsole::place(bid, ask);
}