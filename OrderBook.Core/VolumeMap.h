#pragma once
#include <map>
#include <tuple>

class VolumeMap
{
private:
	/// <summary>
	/// Key that contains the Price and Side and Volume as value of Hashmap.
	/// </summary>
	//std::map<std::tuple<double, bool>, int> m;

public:
	VolumeMap();
	~VolumeMap();

};