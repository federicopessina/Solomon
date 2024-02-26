#pragma once
#include <chrono>
#include <string>

class Order
{
private:
	std::string	mId;
	std::time_t	mTimestamp;
	bool		mIsBuy;
	double		mPrice;
	int			mVolume;
	std::string	mTicker;
	std::string	mClient;

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