#include <chrono>
#include "Order.h"

Order::Order(std::string id, bool isBuy, double price, int volume, std::string ticker, std::string client)
{
	const auto now = std::chrono::system_clock::now();

	this->m_id = id;
	this->m_timestamp = std::chrono::system_clock::to_time_t(now);
	this->m_isBuy = isBuy;
	this->m_price = price;
	this->m_volume = volume;
	this->m_ticker = ticker;
	this->m_client = client;
}

Order::~Order()
{
}

std::string Order::getId()
{
	return this->m_id;
}

std::time_t Order::getTimestamp()
{
	return this->m_timestamp;
}

bool Order::getIsBuy()
{
	return this->m_isBuy;
}

double Order::getPrice()
{
	return this->m_price;
}

int Order::getVolume()
{
	return this->m_volume;
}

std::string Order::getTicker()
{
	return this->m_ticker;
}

std::string Order::getClient()
{
	return this->m_client;
}
