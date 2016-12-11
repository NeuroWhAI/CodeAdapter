#ifndef __CA__TEXT_ARTIST_H__
#define __CA__TEXT_ARTIST_H__


#include "BasicDeclaration.h"

#include "Artist.h"

#include "TextAligns.h"




BEGIN_NAMESPACE_CA_DRAWING


class TextArtist : public Artist
{
private:
	USING_CA_DRAWING(RectangleF);

	USING_CA_UTILITY(String);


public:
	TextArtist();
	virtual ~TextArtist();


public:
	virtual void beginDrawString(Font& font) = 0;
	virtual void endDrawString() = 0;
	virtual RectangleF getBoundRectangle(const String& text) = 0;
	virtual void drawString(const String& text, i32 x, i32 y, const Color& color,
		TextAligns align = TextAligns::RightBottom) = 0;
	virtual void drawString(const String& text, const Point& location, const Color& color,
		TextAligns align = TextAligns::RightBottom) = 0;
	virtual void drawString(const String& text, f32 x, f32 y, const Color& color,
		TextAligns align = TextAligns::RightBottom) = 0;
	virtual void drawString(const String& text, const PointF& location, const Color& color,
		TextAligns align = TextAligns::RightBottom) = 0;
};


END_NAMESPACE_CA_DRAWING


#endif