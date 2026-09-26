#include <iostream>
#include <ostream>
#include <random>

#include "Book.h"
#include "Order.h"
#include "OrderBook.Core.h"
#include "OrderConsole.h"
#include "VolumeStore.h"
#include "Wait.h"

int main()
{
	std::cout << "Hello Solomon Console" << std::endl << std::endl;

	auto book = new Book();
	auto volumeStore = new VolumeStore();

	std::string ticker = "GOOG";						// Fixed ticker

	while (true)
	{
		wait();

		// Random numbers generation.
		int		randomId		= std::rand() % 999;	// Random int in range 0-999.
		int		randomPrice		= std::rand() % 100;	// Random int in range 0-100.
		bool	randomIsBuy		= std::rand() % 2;		// 1 is converted to true and 0 as false.
		int		randomVolume	= std::rand() % 999;	// Random int in range 0-999.
		int		randomClient	= std::rand() % 50;		// Random int in range 0-50.

		auto randomOrder = new Order(
			std::to_string(randomId),
			randomIsBuy,
			(double)randomPrice,
			randomVolume,
			ticker,
			std::to_string(randomClient));


		if (volumeStore->contains(randomOrder->getId()))
			continue;

		OrderConsole::print(*randomOrder);

		book->add(*randomOrder);
		volumeStore->add(*randomOrder);

		book->match();

	}

	return 0;
}
