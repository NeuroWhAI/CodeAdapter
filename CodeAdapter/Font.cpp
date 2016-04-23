#include "Font.h"




BEGIN_NAMESPACE_CA_DRAWING


Font::Font()
	: m_charSize(0)
	, m_style(FontStyles::Regular)
{

}


Font::~Font()
{

}

//###########################################################################

bool Font::loadFromFile(const Utility::String& filename)
{
	bool bSuccess = whenLoadFromFile(filename);

	if (bSuccess)
	{
		m_fileName = filename;
	}
	else
	{
		m_fileName = "";
	}


	return bSuccess;
}

//###########################################################################

Utility::String Font::getName() const
{
	return m_fileName;
}

//###########################################################################

i32 Font::getCharacterSize() const
{
	return m_charSize;
}


void Font::setCharacterSize(i32 height)
{
	whenSetCharacterSize(height);

	m_charSize = height;
}

//###########################################################################

i32 Font::getStyle() const
{
	return m_style;
}


bool Font::checkStyle(i32 style) const
{
	return ((m_style - style) == (m_style & (~style)));
}


bool Font::isRegularStyle() const
{
	return ((m_style == FontStyles::Regular != 0));
}


bool Font::hasBoldStyle() const
{
	return ((m_style & FontStyles::Bold) != 0);
}


bool Font::hasItalicStyle() const
{
	return ((m_style & FontStyles::Italic) != 0);
}


bool Font::hasStrikeOutStyle() const
{
	return ((m_style & FontStyles::StrikeOut) != 0);
}


bool Font::hasUnderlineStyle() const
{
	return ((m_style & FontStyles::Underline) != 0);
}

//###########################################################################

void Font::setStyle(i32 style)
{
	whenSetStyle(style);

	m_style = style;
}


void Font::addStyle(i32 style)
{
	whenSetStyle(m_style | style);

	m_style |= style;
}


void Font::removeStyle(i32 style)
{
	whenSetStyle(m_style & (~style));

	m_style &= (~style);
}


END_NAMESPACE_CA_DRAWING

