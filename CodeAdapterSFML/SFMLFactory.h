#ifndef __CA_SFML__FACTORY_H__
#define __CA_SFML__FACTORY_H__


#include "CodeAdapter\Factory.h"

#include "CodeAdapter\SharedObject.h"




namespace sf
{
	class RenderWindow;
	class Text;
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


public:
	virtual std::shared_ptr<CodeAdapter::Drawing::Window> createWindow() override;
	virtual std::shared_ptr<CodeAdapter::Drawing::TextArtist> createTextArtist() override;
	virtual std::shared_ptr<CodeAdapter::Drawing::RectangleArtist> createRectangleArtist() override;
	virtual std::shared_ptr<CodeAdapter::Drawing::EllipseArtist> createEllipseArtist() override;
	virtual std::shared_ptr<CodeAdapter::Drawing::LineArtist> createLineArtist() override;
	virtual std::shared_ptr<CodeAdapter::Drawing::Font> createFont() override;
};


#endif