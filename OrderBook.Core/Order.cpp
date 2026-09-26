#include <chrono>
#include "Order.h"

Order::Order(std::string id, bool isBuy, double price, int volume, std::string ticker, std::string client)
{
	const auto now = std::chrono::system_clock::now();

	this->m_id_ = id;
	this->m_timestamp_ = std::chrono::system_clock::to_time_t(now);
	this->m_is_buy_ = isBuy;
	this->m_price_ = price;
	this->m_volume_ = volume;
	this->m_ticker_ = ticker;
	this->m_client_ = client;
}

Order::~Order()
{
}

std::string Order::getId() const
{
	return m_id_;
}

std::time_t Order::getTimestamp() const
{
	return m_timestamp_;
}

bool Order::getIsBuy() const
{
	return m_is_buy_;
}

double Order::getPrice() const
{
	return m_price_;
}

int Order::getVolume() const
{
	return m_volume_;
}

std::string Order::getTicker() const
{
	return m_ticker_;
}

std::string Order::getClient() const
{
	return m_client_;
}
