#ifndef __CA_SFML__TEXT_ARTIST_H__
#define __CA_SFML__TEXT_ARTIST_H__


#include "CodeAdapter\TextArtist.h"

#include "SFML\Graphics.hpp"




class TextArtist : public CodeAdapter::Drawing::TextArtist
{
private:
	USING_CA(i32);
	USING_CA(f32);

	USING_CA_UTILITY(String);
	USING_CA_UTILITY_T(SharedObject, T);

	USING_CA_DRAWING(Color);
	USING_CA_DRAWING(Point);
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(Font);


public:
	TextArtist(SharedObject<sf::RenderWindow>& sharedWin,
		SharedObject<sf::Text>& sharedFontText);
	virtual ~TextArtist();


protected:
	SharedObject<sf::RenderWindow>& m_sharedWin;
	sf::RenderStates m_renderStates;


protected:
	sf::Text* m_text;
	SharedObject<sf::Text>& m_sharedFontText;


protected:
	void updateRenderTransform();


public:
	virtual void beginDrawString(Font& font) override;
	virtual void endDrawString() override;
	virtual void drawString(const String& text, i32 x, i32 y, const Color& color) override;
	virtual void drawString(const String& text, const Point& location, const Color& color)override;
	virtual void drawString(const String& text, f32 x, f32 y, const Color& color) override;
	virtual void drawString(const String& text, const PointF& location, const Color& color) override;
};


#endif