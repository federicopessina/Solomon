#pragma once
#include <chrono>
#include <string>

class Order
{
private:
	std::string	m_id_;
	std::time_t	m_timestamp_;
	bool		m_is_buy_;
	double		m_price_;
	int			m_volume_;
	std::string	m_ticker_;
	std::string	m_client_;

public:
	Order(std::string id, bool isBuy, double price, int volume, std::string ticker, std::string client);
	~Order();

	std::string getId() const;
	std::time_t getTimestamp() const;
	bool getIsBuy() const;
	double getPrice() const;
	int getVolume() const;
	std::string getTicker() const;
	std::string getClient() const;
};