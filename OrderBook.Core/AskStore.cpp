#include "AskStore.h"

AskStore::AskStore()
{
}

AskStore::~AskStore()
{
}

void AskStore::add(Order order)
{
	m_orders_.push(order);
}

bool AskStore::isEmpty()
{
	if (m_orders_.empty())
		return true;

	return false;
}

void AskStore::removeTop()
{
	if (this->isEmpty())
		return;

	m_orders_.pop();
}

int AskStore::size()
{
	return static_cast<int>(m_orders_.size());
}

Order AskStore::top()
{
	return m_orders_.top();
}
