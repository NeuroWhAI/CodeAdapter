#include "Font.h"

#include "CodeAdapter\String.h"
#include "CodeAdapter\SharedObject.h"




Font::Font(SharedObject<sf::Text>& sharedFontText)
	: m_sharedFontText(sharedFontText)
{
	m_text.setFont(m_font);
}


Font::~Font()
{

}

//###########################################################################

void Font::attach()
{
	m_sharedFontText.pushObject(&m_text);
}


void Font::detach()
{
	m_sharedFontText.popObject();
}

//###########################################################################

bool Font::whenLoadFromFile(const String& filename)
{
	return m_font.loadFromFile(static_cast<std::string>(filename));
}


void Font::whenSetCharacterSize(i32 height)
{
	m_text.setCharacterSize(height);
}


void Font::whenSetStyle(i32 style)
{
	using CodeAdapter::Drawing::FontStyles;


	sf::Uint32 sfStyle = sf::Text::Regular;

	if ((style & FontStyles::Bold) != 0)
		sfStyle |= sf::Text::Bold;
	if ((style & FontStyles::Italic) != 0)
		sfStyle |= sf::Text::Italic;
	if ((style & FontStyles::StrikeOut) != 0)
		sfStyle |= sf::Text::StrikeThrough;
	if ((style & FontStyles::Underline) != 0)
		sfStyle |= sf::Text::Underlined;

	m_text.setStyle(sfStyle);
}

