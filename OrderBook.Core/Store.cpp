#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
}

void Store::add(Order& order)
{

	throw NULL;
}

Order Store::get(std::string id)
{

	throw NULL;
}

void Store::remove(Order order)
{

	throw NULL;

}

bool Comparer::operator()(Order& a, Order& b)
{
	double aPrice = a.getPrice(), bPrice = b.getPrice();

	return aPrice < bPrice ? true : false;
}
