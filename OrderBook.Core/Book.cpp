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
		mBids.add(order);
	}
	else
	{
		mAsks.add(order);
	}
}

void Book::cancel(std::string id)
{
	return;
}

int Book::getBidsSize()
{
	return mBids.size();
}

int Book::getAsksSize()
{
	return mAsks.size();
}

int Book::getVolumeAtPrice(double price, bool isBid)
{
	return 0;
}

void Book::match()
{
	if (mBids.isEmpty() || mAsks.isEmpty())
		return;

	Order topBid = mBids.top(), topAsk = mAsks.top();
	int topBidVolume = topBid.getVolume(), topAskVolume = topAsk.getVolume();

	if (topBid.getPrice() >= topAsk.getPrice())
	{
		place(topBid, topAsk);

		mBids.removeTop();
		mAsks.removeTop();

		match();
	}

	return;
}

void Book::place(Order& bid, Order& ask)
{
	BookConsole::place(bid, ask);
}