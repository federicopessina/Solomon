#include <string>
#include "pch.h"
#include "..\OrderBook.Core\Order.cpp"
#include "..\OrderBook.Core\AskStore.cpp"
#include "..\OrderBook.Core\BidStore.cpp"

TEST(TestSuiteName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(BidStore, add_addsElement)
{
	// Arrange
	const std::string	id		= "qwerty";
	const bool			isBuy	= false;
	const double		price	= 1.1;
	const int			volume	= 101;
	const std::string	ticker	= "AMZN";
	const std::string	client	= "Jordan Belfor";

	Order* order = new Order(id, isBuy, price, volume, ticker, client);
	BidStore* store = new BidStore();

	store->add(*order);

	bool isEmpty = store->isEmpty();

	EXPECT_FALSE(isEmpty);
}

TEST(BidStore, add_addsMultipleElements)
{
	// Arrange
	const std::string	id = "qwerty";
	const bool			isBuy = false;
	const double		price = 1.1;
	const int			volume = 101;
	const std::string	ticker = "AMZN";
	const std::string	client = "Jordan Belfor";

	BidStore* store = new BidStore();

	const int numberOfOrders = 100;
	for (int i = 0; i < numberOfOrders; i++)
	{
		Order* order = new Order(id, isBuy, price, volume, ticker, client);
		store->add(*order);
	}

	int storeSize = store->size();
	EXPECT_EQ(numberOfOrders, storeSize);
}

TEST(BidStore, top_returnsElement)
{
	// Arrange
	const std::string	id = "qwerty";
	const bool			isBuy = false;
	const double		price = 1.1;
	const int			volume = 101;
	const std::string	ticker = "AMZN";
	const std::string	client = "Jordan Belfor";

	Order* order = new Order(id, isBuy, price, volume, ticker, client);
	BidStore* store = new BidStore();

	store->add(*order);

	Order topOrder = store->top();

	EXPECT_EQ(order->getId(), topOrder.getId());
	EXPECT_EQ(order->getIsBuy(), topOrder.getIsBuy());
	EXPECT_EQ(order->getTicker(), topOrder.getTicker());
	EXPECT_EQ(order->getTimestamp(), topOrder.getTimestamp());
	EXPECT_EQ(order->getVolume(), topOrder.getVolume());
}

TEST(BidStore, top_returnsElement_withMaxPrice)
{
	// Arrange
	const std::string	id = "qwerty";
	const bool			isBuy = false;
	const double		price = 1.1;
	const int			volume = 101;
	const std::string	ticker = "AMZN";
	const std::string	client = "Jordan Belfor";

	int numberOfElements = 100;
	std::vector<double> randomPrices;
	for (int i = 0; i < numberOfElements; i++)
	{
		double randomPrice = rand() % 100;
		randomPrices.push_back(randomPrice);
	}

	BidStore* store = new BidStore();
	
	for (auto price : randomPrices)
	{
		Order* order = new Order(id, isBuy, (double)price, volume, ticker, client);
		store->add(*order);
	}

	Order topOrder = store->top();

	double maxPrice = *std::max_element(std::begin(randomPrices), std::end(randomPrices));

	EXPECT_EQ(maxPrice, topOrder.getPrice());
}

TEST(AskStore, top_returnsElement_withMinPrice)
{
	// Arrange
	const std::string	id = "qwerty";
	const bool			isBuy = false;
	const double		price = 1.1;
	const int			volume = 101;
	const std::string	ticker = "AMZN";
	const std::string	client = "Jordan Belfor";

	int numberOfElements = 100;
	std::vector<double> randomPrices;
	for (int i = 0; i < numberOfElements; i++)
	{
		double randomPrice = rand() % 100;
		randomPrices.push_back(randomPrice);
	}

	AskStore* store = new AskStore();

	for (auto price : randomPrices)
	{
		Order* order = new Order(id, isBuy, (double)price, volume, ticker, client);
		store->add(*order);
	}

	Order topOrder = store->top();

	double minPrice = *std::min_element(std::begin(randomPrices), std::end(randomPrices));

	EXPECT_EQ(minPrice, topOrder.getPrice());
}

//
//TEST(Order, Constructor_InitializesFields) {
//	// Arrange
//	const std::string id = "qwerty";
//	const bool isBuy = false;
//	const double price = 1.1;
//	const int volume = 101;
//	const std::string ticker = "AMZN";
//	const std::string client = "Jordan Belfor";
//	
//	// Act
//	Order* order = new Order(id, isBuy, price, volume, ticker, client);
//
//	// Assert
//	EXPECT_EQ(id, order->getId());
//	// TODO Test timestamp
//	EXPECT_EQ(isBuy, order->getIsBuy());
//	EXPECT_EQ(price, order->getPrice());
//	EXPECT_EQ(volume, order->getVolume());
//	EXPECT_EQ(ticker, order->getTicker());
//	EXPECT_EQ(client, order->getClient());
//}
//
//TEST(BidStore, addOrder_AddsuMultipleOrders_EqualPrice) {
//	// Arrange
//	const std::string id = "qwerty";
//	const bool isBuy = false;
//	const double price = 1.1;
//	const int volume = 101;
//	const std::string ticker = "AMZN";
//	const std::string client = "Jordan Belfor";
//
//	// Act
//	auto store = new BidStore();
//
//	const int number_of_orders = 10;
//	for (int i = 0; i < number_of_orders; i++)
//	{
//		auto order = new Order(id, isBuy, price, volume, ticker, client);
//		store->add(*order);
//	}
//
//	// Assert
//	auto result = store->get();
//
//	EXPECT_NE(false, store.isEmpty());
//	EXPECT_EQ(number_of_orders, result.size());
//}
//
//TEST(BidStore, addOrder_AddsuMultipleOrders_DifferentPrice) {
//	// Arrange
//	const std::string id = "qwerty";
//	const bool isBuy = false;
//	const double price = 1.1;
//	const int volume = 101;
//	const std::string ticker = "AMZN";
//	const std::string client = "Jordan Belfor";
//
//	// Act
//	auto store = new Store(true);
//
//	const int number_of_orders = 10;
//	for (int i = 0; i < number_of_orders; i++)
//	{
//		auto order = new Order(id, isBuy, (double)i, volume, ticker, client);
//		store->add(*order);
//	}
//
//	// Assert
//	auto result = store->get();
//	EXPECT_EQ(number_of_orders, result.size());
//}

//TEST(Store, getTop_getCorrect_InStore) {
//	// Arrange
//	const std::string id = "qwerty";
//	const bool isBuy = false;
//	const int volume = 101;
//	const std::string ticker = "AMZN";
//	const std::string client = "Jordan Belfor";
//	
//	const double price1 = 1.0, price2 = 2.0, price3 = 3.0, price4 = 4.0, price5 = 5.0;
//
//	auto order1 = new Order(id, isBuy, price1, volume, ticker, client);
//	auto order2 = new Order(id, isBuy, price2, volume, ticker, client);
//	auto order3 = new Order(id, isBuy, price3, volume, ticker, client);
//	auto order4 = new Order(id, isBuy, price4, volume, ticker, client);
//	auto order5 = new Order(id, isBuy, price5, volume, ticker, client);
//	
//	bool isBuySide = true;
//
//	auto storeBuySide = new Store(isBuySide);
//	storeBuySide->add(*order2);
//	storeBuySide->add(*order1);
//	storeBuySide->add(*order5);
//	storeBuySide->add(*order3);
//	storeBuySide->add(*order4);
//
//	auto storeSellSide = new Store(!isBuySide);
//	storeSellSide->add(*order2);
//	storeSellSide->add(*order3);
//	storeSellSide->add(*order1);
//	storeSellSide->add(*order5);
//	storeSellSide->add(*order4);
//
//	// Act
//	auto topBuySide = storeBuySide->getTop();
//	auto topSellSide = storeSellSide->getTop();
//	
//	// Assert
//	EXPECT_EQ(price5, topBuySide.getPrice());
//	EXPECT_EQ(price1, topSellSide.getPrice());
//}
//
//TEST(BidStore, getTop_getCorrect_InMaxHeap) {
//	// Arrange
//	const std::string id = "qwerty";
//	const bool isBuy = false;
//	const int volume = 101;
//	const std::string ticker = "AMZN";
//	const std::string client = "Jordan Belfor";
//
//	std::vector<int> randomPrices;
//	for (int i = 0; i < 100; i++)
//	{
//		int randomPrice = rand() % 100;
//		randomPrices.push_back(randomPrice);
//	}
//
//	Store bids = new BidStore();
//
//	for (auto price : randomPrices)
//	{
//		auto order = new Order(id, isBuy, (double)price, volume, ticker, client);
//		bids.add(*order);
//	}
//
//	// Act
//	Order topBid = bids.getTop();
//
//	// Assert
//	double maxPriceInPrices = *std::max_element(std::begin(randomPrices), std::end(randomPrices));
//	double result = topBid.getPrice();
//
//	EXPECT_EQ(maxPriceInPrices, result);
//}
//
//TEST(BidStore, getTop_getCorrect_InMinHeap) {
//	// Arrange
//	const std::string id = "qwerty";
//	const bool isBuy = false;
//	const int volume = 101;
//	const std::string ticker = "AMZN";
//	const std::string client = "Jordan Belfor";
//
//	std::vector<int> randomPrices;
//	for (int i = 0; i < 100; i++)
//	{
//		int randomPrice = rand() % 100;
//		randomPrices.push_back(randomPrice);
//	}
//
//	bool isBuySide = false; // sell side >> offer >> min heap based on price
//	BidStore bids = new BidStore(isBuySide);
//
//	for (auto price : randomPrices)
//	{
//		auto order = new Order(id, isBuy, (double)price, volume, ticker, client);
//		bids.add(*order);
//	}
//
//	// Act
//	Order topAsk = bids.getTop();
//
//	// Assert
//	double minPriceInPrices = *std::min_element(std::begin(randomPrices), std::end(randomPrices));
//	double result = topAsk.getPrice();
//
//	EXPECT_EQ(minPriceInPrices, result);
//}