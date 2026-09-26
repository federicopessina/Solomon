#include "BidStore.h"

BidStore::BidStore()
{
}

BidStore::~BidStore()
{
}

void BidStore::add(Order order)
{
	m_orders_.push(order);
}

bool BidStore::isEmpty()
{
	if (m_orders_.empty())
		return true;

	return false;
}

void BidStore::removeTop()
{
	if (this->isEmpty())
		return;

	m_orders_.pop();
}

int BidStore::size()
{
	return static_cast<int>(m_orders_.size());
}

Order BidStore::top()
{
	Order result = m_orders_.top();
	return result;
}
