#include "ResourcePool.h"




BEGIN_NAMESPACE_CA_UTILITY


template <typename T>
std::shared_ptr<T> ResourcePool::createHelper(const String& key,
	MapType<T>& map,
	std::function<std::shared_ptr<T>(void)> creator)
{
	auto rcPair = map.find(key);

	if (rcPair == map.end())
	{
		auto rc = creator();

		map.insert(std::make_pair(key, rc));


		return rc;
	}


	return nullptr;
}


template <typename T>
std::shared_ptr<T> ResourcePool::getHelper(const String& key,
	MapType<T>& map)
{
	auto rcPair = map.find(key);

	if (rcPair != map.end())
	{
		return rcPair->second;
	}


	return nullptr;
}


END_NAMESPACE_CA_UTILITY

