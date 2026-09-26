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
	m_map_.try_emplace(id, volume);
}

bool VolumeStore::contains(std::string id)
{
	if (m_map_.find(id) != m_map_.end())
		return true;

	return false;
}

void VolumeStore::remove(std::string id)
{
	m_map_.erase(id);
}

void VolumeStore::remove(Order order)
{
	VolumeStore::remove(order.getId());
}

void VolumeStore::subtract(std::string id, int volume)
{
	if (m_map_.empty())
		return; //TODO Handle.

	m_map_[id] -= volume;

}

int VolumeStore::get(std::string id)
{
	if (m_map_.empty())
		return 0; // TODO Handle.

	return m_map_[id];
}
