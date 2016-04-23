#ifndef __CA__TEXT_ARTIST_H__
#define __CA__TEXT_ARTIST_H__


#include "BasicDeclaration.h"

#include "Artist.h"




BEGIN_NAMESPACE_CA_DRAWING


class TextArtist : public Artist
{
private:
	USING_CA_UTILITY(String);


public:
	TextArtist();
	virtual ~TextArtist();


public:
	virtual void beginDrawString(Font& font, const Color& color) = 0;
	virtual void endDrawString() = 0;
	virtual void drawString(const String& text, int x, int y) = 0;
	virtual void drawString(const String& text, const Point& location) = 0;
	virtual void drawString(const String& text, float x, float y) = 0;
	virtual void drawString(const String& text, const PointF& location) = 0;
};


END_NAMESPACE_CA_DRAWING


#endif