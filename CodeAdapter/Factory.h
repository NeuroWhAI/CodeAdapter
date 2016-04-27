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
	virtual std::shared_ptr<Drawing::Window> createWindow() = 0;
	virtual std::shared_ptr<Drawing::TextArtist> createTextArtist() = 0;
	virtual std::shared_ptr<Drawing::RectangleArtist> createRectangleArtist() = 0;
	virtual std::shared_ptr<Drawing::EllipseArtist> createEllipseArtist() = 0;
	virtual std::shared_ptr<Drawing::LineArtist> createLineArtist() = 0;
	virtual std::shared_ptr<Drawing::TextureArtist> createTextureArtist() = 0;
	virtual std::shared_ptr<Drawing::Font> createFont() = 0;
	virtual std::shared_ptr<Drawing::Texture> createTexture() = 0;


public:
	virtual std::shared_ptr<System::Touch> createTouch() = 0;
};


END_NAMESPACE_CA


#include "Factory.inl"


#endif