#pragma once

class IVolumeMap
{
public:
	virtual void add(Order order) = 0;
	virtual void add(std::string id, int volume) = 0;
	virtual void remove(std::string id) = 0;
	virtual void remove(Order order) = 0;
	virtual void subtract(std::string id, int volume) = 0;
	virtual int get(std::string id) = 0;
};