#include "BidStore.h"

BidStore::BidStore()
{
}

BidStore::~BidStore()
{
}

void BidStore::add(Order order)
{
	m_orders.push(order);
}

bool BidStore::isEmpty()
{
	if (m_orders.empty())
		return true;

	return false;
}

int BidStore::size()
{
	return (int)m_orders.size();
}

Order BidStore::top()
{
	Order result = m_orders.top();
	return result;
}
