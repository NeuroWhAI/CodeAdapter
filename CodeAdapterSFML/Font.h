#ifndef __CA_SFML__FONT_H__
#define __CA_SFML__FONT_H__


#include "CodeAdapter\Font.h"

#include "SFML\Graphics.hpp"




class Font : public CodeAdapter::Drawing::Font
{
private:
	USING_CA(i32);

	USING_CA_UTILITY(String);
	USING_CA_UTILITY_T(SharedObject, T);


protected:
	sf::Font m_font;
	sf::Text m_text;
	SharedObject<sf::Text>& m_sharedFontText;


public:
	explicit Font(SharedObject<sf::Text>& sharedFontText);
	virtual ~Font();


public:
	virtual void attach() override;
	virtual void detach() override;


protected:
	virtual bool whenLoadFromFile(const String& filename) override;
	virtual void whenSetCharacterSize(i32 height) override;
	virtual void whenSetStyle(i32 style) override;
};


#endif