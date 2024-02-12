#include <string>
#include "pch.h"

#include "..\OrderBook.Core\Order.cpp"
#include "..\OrderBook.Core\Store.cpp"

TEST(TestSuiteName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(Order, ConstructorInitializesFields) {
	// Arrange
	const std::string id = "qwerty";
	const bool isBuy = false;
	const double price = 1.1;
	const int volume = 101;
	const std::string ticker = "AMZN";
	const std::string client = "Jordan Belfor";
	
	// Act
	Order* order = new Order(id, isBuy, price, volume, ticker, client);

	// Assert
	EXPECT_EQ(id, order->getId());
	// TODO Test timestamp
	EXPECT_EQ(isBuy, order->getIsBuy());
	EXPECT_EQ(price, order->getPrice());
	EXPECT_EQ(volume, order->getVolume());
	EXPECT_EQ(ticker, order->getTicker());
	EXPECT_EQ(client, order->getClient());
}

//TEST(Store, addOrderAddsAnOrder) {
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
//	Store* store = new Store();
//	store->add(*order);
//
//	// Assert
//	auto result = store->get();
//	EXPECT_NE(0, result.size());
//}
//
//TEST(Store, addOrderAddsuMultipleOrders) {
//	// Arrange
//	const std::string id = "qwerty";
//	const bool isBuy = false;
//	const double price = 1.1;
//	const int volume = 101;
//	const std::string ticker = "AMZN";
//	const std::string client = "Jordan Belfor";
//
//	// Act
//	auto store = new Store();
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
//	EXPECT_EQ(number_of_orders, result.size());
//}
//
//TEST(Store, addOrderAddsOrderByPrice) {
//	// Arrange
//	const std::string id = "qwerty";
//	const bool isBuy = false;
//	const double price = 1.1;
//	const int volume = 101;
//	const std::string ticker = "AMZN";
//	const std::string client = "Jordan Belfor";
//
//	// Act
//	auto store = new Store();
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
