#include "AskStore.h"

AskStore::AskStore()
{
}

AskStore::~AskStore()
{
}

void AskStore::add(Order order)
{
	m_orders.push(order);
}

bool AskStore::isEmpty()
{
	if (m_orders.empty())
		return true;

	return false;
}

int AskStore::size()
{
	return (int)m_orders.size();
}

Order AskStore::top()
{
	return m_orders.top();
}
