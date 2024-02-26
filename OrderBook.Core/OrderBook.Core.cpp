// OrderBook.Core.cpp : Defines the entry point for the application.
//

#include <chrono>
#include <random>
#include <thread>
#include "Book.h"
#include "Order.h"
#include "OrderBook.Core.h"
#include "OrderConsole.h"

int main()
{
	std::cout << "Hello Solomon Core" << std::endl << std::endl;

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

void wait()
{
	// Time waiter.
	using namespace std::this_thread;				// sleep_for, sleep_until
	using namespace std::chrono_literals;			// ns, us, ms, s, h, etc.
	using std::chrono::system_clock;
	std::this_thread::sleep_for(10ns);
	std::this_thread::sleep_until(system_clock::now() + 1s);
}
