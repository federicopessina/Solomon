#include <chrono>
#include "Order.h"

Order::Order(std::string id, bool isBuy, double price, int volume, std::string ticker, std::string client)
{
	const auto now = std::chrono::system_clock::now();

	this->mId = id;
	this->mTimestamp = std::chrono::system_clock::to_time_t(now);
	this->mIsBuy = isBuy;
	this->mPrice = price;
	this->mVolume = volume;
	this->mTicker = ticker;
	this->mClient = client;
}

Order::~Order()
{
}

std::string Order::getId() const
{
	return mId;
}

std::time_t Order::getTimestamp() const
{
	return mTimestamp;
}

bool Order::getIsBuy() const
{
	return mIsBuy;
}

double Order::getPrice() const
{
	return mPrice;
}

int Order::getVolume() const
{
	return mVolume;
}

std::string Order::getTicker() const
{
	return mTicker;
}

std::string Order::getClient() const
{
	return mClient;
}
