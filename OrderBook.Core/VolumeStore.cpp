#include "VolumeStore.h"

VolumeStore::VolumeStore()
{
}

VolumeStore::~VolumeStore()
{
}

void VolumeStore::add(Order order)
{
	VolumeStore::add(order.getId(), order.getVolume());
}

void VolumeStore::add(std::string id, int volume)
{
	mMap.try_emplace(id, volume);
}

bool VolumeStore::contains(std::string id)
{
	if (mMap.find(id) != mMap.end())
		return true;

	return false;
}

void VolumeStore::remove(std::string id)
{
	mMap.erase(id);
}

void VolumeStore::remove(Order order)
{
	VolumeStore::remove(order.getId());
}

void VolumeStore::subtract(std::string id, int volume)
{
	if (mMap.empty())
		return; //TODO Handle.

	mMap[id] -= volume;

}

int VolumeStore::get(std::string id)
{
	if (mMap.empty())
		return 0; // TODO Handle.

	return mMap[id];
}
