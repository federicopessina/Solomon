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

std::string Order::getId() const
{
	return m_id;
}

std::time_t Order::getTimestamp() const
{
	return m_timestamp;
}

bool Order::getIsBuy() const
{
	return m_isBuy;
}

double Order::getPrice() const
{
	return m_price;
}

int Order::getVolume() const
{
	return m_volume;
}

std::string Order::getTicker() const
{
	return m_ticker;
}

std::string Order::getClient() const
{
	return m_client;
}
