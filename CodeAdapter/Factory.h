#ifndef __CA__FACTORY_H__
#define __CA__FACTORY_H__


#include <memory>

#include "BasicDeclaration.h"


BEGIN_NAMESPACE_CA


class Factory
{
public:
	Factory();
	virtual ~Factory();


private:
	static Factory* s_pInstance;

	class CleanUp
	{
	public:
		virtual ~CleanUp()
		{
			if (s_pInstance != nullptr)
			{
				delete s_pInstance;
				s_pInstance = nullptr;
			}
		}
	};

	static CleanUp s_cleaner;


public:
	template <typename T>
	static void initializeInstance();
	static Factory* getInstance();


public:
	virtual Drawing::WindowPtr createWindow() = 0;
	virtual Drawing::PanelPtr createPanel() = 0;
	virtual Drawing::TextArtistPtr createTextArtist() = 0;
	virtual Drawing::RectangleArtistPtr createRectangleArtist() = 0;
	virtual Drawing::EllipseArtistPtr createEllipseArtist() = 0;
	virtual Drawing::LineArtistPtr createLineArtist() = 0;
	virtual Drawing::TextureArtistPtr createTextureArtist() = 0;
	virtual Drawing::FontPtr createFont() = 0;
	virtual Drawing::TexturePtr createTexture() = 0;


public:
	virtual System::TouchPtr createTouch() = 0;
	virtual System::KeyboardPtr createKeyboard() = 0;


public:
	virtual Audio::SoundPtr createSound() = 0;
};


END_NAMESPACE_CA


#include "Factory.inl"


#endif