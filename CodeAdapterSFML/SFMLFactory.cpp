#include "SFMLFactory.h"

#include "SFML\Graphics.hpp"

#include "Window.h"
#include "Panel.h"
#include "TextArtist.h"
#include "RectangleArtist.h"
#include "EllipseArtist.h"
#include "LineArtist.h"
#include "TextureArtist.h"
#include "Font.h"
#include "Texture.h"

#include "Touch.h"
#include "Keyboard.h"

#include "Sound.h"




SFMLFactory::SFMLFactory()
{

}


SFMLFactory::~SFMLFactory()
{

}

//###########################################################################

CodeAdapter::Drawing::WindowPtr SFMLFactory::createWindow()
{
	return std::make_shared<Window>(m_sharedWindow);
}


CodeAdapter::Drawing::PanelPtr SFMLFactory::createPanel()
{
	return std::make_shared<Panel>(m_sharedWindow);
}


CodeAdapter::Drawing::TextArtistPtr SFMLFactory::createTextArtist()
{
	return std::make_shared<TextArtist>(m_sharedWindow, m_sharedFontText);
}


CodeAdapter::Drawing::RectangleArtistPtr SFMLFactory::createRectangleArtist()
{
	return std::make_shared<RectangleArtist>(m_sharedWindow);
}


CodeAdapter::Drawing::EllipseArtistPtr SFMLFactory::createEllipseArtist()
{
	return std::make_shared<EllipseArtist>(m_sharedWindow);
}


CodeAdapter::Drawing::LineArtistPtr SFMLFactory::createLineArtist()
{
	return std::make_shared<LineArtist>(m_sharedWindow);
}


CodeAdapter::Drawing::TextureArtistPtr SFMLFactory::createTextureArtist()
{
	return std::make_shared<TextureArtist>(m_sharedWindow, m_sharedTexture);
}


CodeAdapter::Drawing::FontPtr SFMLFactory::createFont()
{
	return std::make_shared<Font>(m_sharedFontText);
}

CodeAdapter::Drawing::TexturePtr SFMLFactory::createTexture()
{
	return std::make_shared<Texture>(m_sharedTexture);
}

//###########################################################################

CodeAdapter::System::TouchPtr SFMLFactory::createTouch()
{
	return std::make_shared<Touch>(m_sharedWindow);
}


CodeAdapter::System::KeyboardPtr SFMLFactory::createKeyboard()
{
	return std::make_shared<Keyboard>();
}

//###########################################################################

CodeAdapter::Audio::SoundPtr SFMLFactory::createSound()
{
	return std::make_shared<Sound>();
}

