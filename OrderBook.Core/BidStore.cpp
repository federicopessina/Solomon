#include "BidStore.h"

BidStore::BidStore()
{
}

BidStore::~BidStore()
{
}

void BidStore::add(Order order)
{
	mOrders.push(order);
}

bool BidStore::isEmpty()
{
	if (mOrders.empty())
		return true;

	return false;
}

void BidStore::removeTop()
{
	if (this->isEmpty())
		return;

	mOrders.pop();
}

int BidStore::size()
{
	return static_cast<int>(mOrders.size());
}

Order BidStore::top()
{
	Order result = mOrders.top();
	return result;
}
