#include "ResourcePool.h"

#include "Factory.h"

#include "Font.h"
#include "Texture.h"




BEGIN_NAMESPACE_CA_UTILITY


ResourcePool::ResourcePool()
{

}


ResourcePool::~ResourcePool()
{

}

//###########################################################################

auto ResourcePool::createFont(const String& key) -> std::shared_ptr<Font>
{
	return createHelper<Font>(key, m_fontMap,
		[]() { return Factory::getInstance()->createFont(); });
}


auto ResourcePool::createTexture(const String& key) -> std::shared_ptr<Texture>
{
	return createHelper<Texture>(key, m_textureMap,
		[]() { return Factory::getInstance()->createTexture(); });
}


auto ResourcePool::createSound(const String& key) -> std::shared_ptr<Sound>
{
	return createHelper<Sound>(key, m_soundMap,
		[]() { return Factory::getInstance()->createSound(); });
}

//###########################################################################

auto ResourcePool::getFont(const String& key) -> std::shared_ptr<Font>
{
	return getHelper(key, m_fontMap);
}


auto ResourcePool::getTexture(const String& key) -> std::shared_ptr<Texture>
{
	return getHelper(key, m_textureMap);
}


auto ResourcePool::getSound(const String& key) -> std::shared_ptr<Sound>
{
	return getHelper(key, m_soundMap);
}


END_NAMESPACE_CA_UTILITY

