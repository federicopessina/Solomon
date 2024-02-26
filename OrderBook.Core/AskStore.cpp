#include "AskStore.h"

AskStore::AskStore()
{
}

AskStore::~AskStore()
{
}

void AskStore::add(Order order)
{
	mOrders.push(order);
}

bool AskStore::isEmpty()
{
	if (mOrders.empty())
		return true;

	return false;
}

void AskStore::removeTop()
{
	if (this->isEmpty())
		return;

	mOrders.pop();
}

int AskStore::size()
{
	return static_cast<int>(mOrders.size());
}

Order AskStore::top()
{
	return mOrders.top();
}
