#ifndef __CA_SFML__FACTORY_H__
#define __CA_SFML__FACTORY_H__


#include "CodeAdapter\Factory.h"

#include "CodeAdapter\SharedObject.h"




namespace sf
{
	class RenderWindow;
	class Text;
	class Texture;
}


class SFMLFactory : public CodeAdapter::Factory
{
private:
	USING_CA_UTILITY_T(SharedObject, T);


public:
	SFMLFactory();
	virtual ~SFMLFactory();


protected:
	SharedObject<sf::RenderWindow> m_sharedWindow;
	SharedObject<sf::Text> m_sharedFontText;
	SharedObject<sf::Texture> m_sharedTexture;


public:
	virtual CodeAdapter::Drawing::WindowPtr createWindow() override;
	virtual CodeAdapter::Drawing::PanelPtr createPanel() override;
	virtual CodeAdapter::Drawing::TextArtistPtr createTextArtist() override;
	virtual CodeAdapter::Drawing::RectangleArtistPtr createRectangleArtist() override;
	virtual CodeAdapter::Drawing::EllipseArtistPtr createEllipseArtist() override;
	virtual CodeAdapter::Drawing::LineArtistPtr createLineArtist() override;
	virtual CodeAdapter::Drawing::TextureArtistPtr createTextureArtist() override;
	virtual CodeAdapter::Drawing::FontPtr createFont() override;
	virtual CodeAdapter::Drawing::TexturePtr createTexture() override;


public:
	virtual CodeAdapter::System::TouchPtr createTouch() override;
	virtual CodeAdapter::System::KeyboardPtr createKeyboard() override;


public:
	virtual CodeAdapter::Audio::SoundPtr createSound() override;
};


#endif