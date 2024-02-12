#pragma once

#include <chrono>
#include <string>

class Order
{
public:
	Order(std::string id, bool isBuy, double price, int volume, std::string ticker, std::string client);
	~Order();

	std::string getId();
	std::time_t getTimestamp();
	bool getIsBuy();
	double getPrice();
	int getVolume();
	std::string getTicker();
	std::string getClient();

private:
	std::string	m_id;
	std::time_t	m_timestamp;
	bool		m_isBuy;
	double		m_price;
	int			m_volume;
	std::string	m_ticker;
	std::string	m_client;
};