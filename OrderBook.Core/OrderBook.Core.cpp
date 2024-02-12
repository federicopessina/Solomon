// OrderBook.Core.cpp : Defines the entry point for the application.
//

#include "OrderBook.Core.h"
#include "Order.h"
#include "Store.h"

using namespace std;

int main()
{
	cout << "Hello Solomon Core." << endl;

	auto order2 = new Order("BBB", true, 111.0, 2, "BBBB", "bbb");
	auto order3 = new Order("CCC", true, 222.0, 3, "CCCC", "ccc");
	auto order1 = new Order("AAA", true, 100.0, 1, "AMZN", "aaa");

	auto store = new Store();

	store->add(*order3);
	store->add(*order2);
	store->add(*order1);

	for (auto item : store->get())
	{
		std::cout << item.getId() << std::endl;
	}

	return 0;
}
