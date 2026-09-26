#pragma once
#include <map>
#include <tuple>
#include <unordered_map>
#include "Order.h"

class VolumeStore
{
private:
	/// <summary>
	/// Key that contains the Price and Side and Volume as value of Hashmap.
	/// </summary>
	std::unordered_map<std::string, int> m_map_;
public:
	VolumeStore();
	~VolumeStore();

	void add(Order order);
	void add(std::string id, int volume);
	bool contains(std::string id);
	void remove(std::string id);
	void remove(Order order);
	void subtract(std::string id, int volume);
	int get(std::string id);
};