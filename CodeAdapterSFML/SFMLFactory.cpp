#include "SFMLFactory.h"

#include "SFML\Graphics.hpp"

#include "Window.h"
#include "TextArtist.h"
#include "RectangleArtist.h"
#include "EllipseArtist.h"
#include "LineArtist.h"
#include "TextureArtist.h"
#include "Font.h"
#include "Texture.h"

#include "Touch.h"




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
	return std::make_shared<TextArtist>(m_sharedWindow, m_sharedFontText);
}


std::shared_ptr<CodeAdapter::Drawing::RectangleArtist> SFMLFactory::createRectangleArtist()
{
	return std::make_shared<RectangleArtist>(m_sharedWindow);
}


std::shared_ptr<CodeAdapter::Drawing::EllipseArtist> SFMLFactory::createEllipseArtist()
{
	return std::make_shared<EllipseArtist>(m_sharedWindow);
}


std::shared_ptr<CodeAdapter::Drawing::LineArtist> SFMLFactory::createLineArtist()
{
	return std::make_shared<LineArtist>(m_sharedWindow);
}


std::shared_ptr<CodeAdapter::Drawing::TextureArtist> SFMLFactory::createTextureArtist()
{
	return std::make_shared<TextureArtist>(m_sharedWindow, m_sharedTexture);
}


std::shared_ptr<CodeAdapter::Drawing::Font> SFMLFactory::createFont()
{
	return std::make_shared<Font>(m_sharedFontText);
}

std::shared_ptr<CodeAdapter::Drawing::Texture> SFMLFactory::createTexture()
{
	return std::make_shared<Texture>(m_sharedTexture);
}

//###########################################################################

std::shared_ptr<CodeAdapter::System::Touch> SFMLFactory::createTouch()
{
	return std::make_shared<Touch>(m_sharedWindow);
}

