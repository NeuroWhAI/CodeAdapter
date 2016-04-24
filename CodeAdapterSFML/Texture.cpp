#include "Texture.h"

#include "CodeAdapter\String.h"
#include "CodeAdapter\SharedObject.h"

#include "CodeAdapter\Rectangle.h"




Texture::Texture(SharedObject<sf::Texture>& sharedTexture)
	: m_sharedTexture(sharedTexture)
{

}


Texture::~Texture()
{

}

//###########################################################################

bool Texture::loadFromFile(const String& filename)
{
	return m_texture.loadFromFile(static_cast<std::string>(filename));
}


bool Texture::loadFromFile(const String& filename,
	const Rectangle& rectangle)
{
	return m_texture.loadFromFile(static_cast<std::string>(filename),
		sf::IntRect(rectangle.x, rectangle.y, rectangle.width, rectangle.height));
}

//###########################################################################

void Texture::attachToGraphics()
{
	m_sharedTexture.setObject(&m_texture);
}

