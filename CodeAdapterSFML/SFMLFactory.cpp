#include "SFMLFactory.h"

#include "SFML\Graphics.hpp"

#include "Window.h"
#include "TextArtist.h"
#include "RectangleArtist.h"




SFMLFactory::SFMLFactory()
{

}


SFMLFactory::~SFMLFactory()
{

}

//###########################################################################

std::shared_ptr<CodeAdapter::Drawing::Window> SFMLFactory::createWindow()
{
	return std::make_shared<Window>(m_sharedWindow);
}


std::shared_ptr<CodeAdapter::Drawing::TextArtist> SFMLFactory::createTextArtist()
{
	return std::make_shared<TextArtist>();
}


std::shared_ptr<CodeAdapter::Drawing::RectangleArtist> SFMLFactory::createRectangleArtist()
{
	return std::make_shared<RectangleArtist>(m_sharedWindow);
}

