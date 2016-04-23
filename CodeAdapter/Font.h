#ifndef __CA__FONT_H__
#define __CA__FONT_H__


#include "BasicDeclaration.h"

#include "String.h"




BEGIN_NAMESPACE_CA_DRAWING


enum FontStyles : i32
{
	Regular = 0,
	Bold = 1,
	Italic = 1 << 1,
	StrikeOut = 1 << 2,
	Underline = 1 << 3,
};


class Font
{
public:
	Font();
	virtual ~Font();


private:
	Utility::String m_fileName;
	i32 m_charSize;
	i32 m_style;


public:
	bool loadFromFile(const Utility::String& filename);


public:
	Utility::String getName() const;


public:
	i32 getCharacterSize() const;
	void setCharacterSize(i32 height);


public:
	i32 getStyle() const;
	bool checkStyle(i32 style) const;
	bool isRegularStyle() const;
	bool hasBoldStyle() const;
	bool hasItalicStyle() const;
	bool hasStrikeOutStyle() const;
	bool hasUnderlineStyle() const;

	void setStyle(i32 style);
	void addStyle(i32 style);
	void removeStyle(i32 style);


public:
	virtual void attachToGraphics() = 0;


protected:
	virtual bool whenLoadFromFile(const Utility::String& filename) = 0;
	virtual void whenSetCharacterSize(i32 height) = 0;
	virtual void whenSetStyle(i32 style) = 0;
};


END_NAMESPACE_CA_DRAWING


#endif