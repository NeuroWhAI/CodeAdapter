#ifndef __CA__RESOURCE_POOL_H__
#define __CA__RESOURCE_POOL_H__


#include <memory>
#include <unordered_map>
#include <string>
#include <functional>

#include "BasicDeclaration.h"

#include "String.h"




BEGIN_NAMESPACE_CA_UTILITY


class ResourcePool
{
private:
	template <typename T>
	using MapType = std::unordered_map<String, std::shared_ptr<T>, String::Hasher>;

	USING_CA_DRAWING(Font);
	USING_CA_DRAWING(Texture);

	USING_CA_AUDIO(Sound);


public:
	ResourcePool();
	virtual ~ResourcePool();


protected:
	MapType<Font> m_fontMap;
	MapType<Texture> m_textureMap;
	MapType<Sound> m_soundMap;


protected:
	template <typename T>
	std::shared_ptr<T> createHelper(const String& key,
		MapType<T>& map,
		std::function<std::shared_ptr<T>(void)> creator);

	template <typename T>
	std::shared_ptr<T> getHelper(const String& key,
		MapType<T>& map);


public:
	std::shared_ptr<Font> createFont(const String& key);
	std::shared_ptr<Texture> createTexture(const String& key);
	std::shared_ptr<Sound> createSound(const String& key);


public:
	std::shared_ptr<Font> getFont(const String& key);
	std::shared_ptr<Texture> getTexture(const String& key);
	std::shared_ptr<Sound> getSound(const String& key);
};


END_NAMESPACE_CA_UTILITY


#include "ResourcePool.inl"


#endif