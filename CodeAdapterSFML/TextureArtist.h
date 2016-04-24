#ifndef __CA_SFML__TEXTURE_ARTIST_H__
#define __CA_SFML__TEXTURE_ARTIST_H__


#include "CodeAdapter\TextureArtist.h"

#include "SFML\Graphics.hpp"




class TextureArtist : public CodeAdapter::Drawing::TextureArtist
{
private:
	USING_CA(i32);
	USING_CA(f32);

	USING_CA_UTILITY_T(SharedObject, T);

	USING_CA_DRAWING(Color);
	USING_CA_DRAWING(Point);
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(Rectangle);
	USING_CA_DRAWING(Texture);


public:
	TextureArtist(SharedObject<sf::RenderWindow>& sharedWin,
		SharedObject<sf::Texture>& sharedTexture);
	virtual ~TextureArtist();


protected:
	SharedObject<sf::RenderWindow>& m_sharedWin;
	sf::RenderStates m_renderStates;


protected:
	SharedObject<sf::Texture>& m_sharedTexture;
	sf::Sprite m_sprite;


protected:
	void updateRenderTransform();


public:
	virtual void beginDrawTexture() override;
	virtual void endDrawTexture() override;
	virtual void drawTexture(Texture& texture, i32 x, i32 y,
		const Color& maskColor = Color::White) override;
	virtual void drawTexture(Texture& texture, i32 x, i32 y,
		const Rectangle& sliceRectangle,
		const Color& maskColor = Color::White) override;
	virtual void drawTexture(Texture& texture, const Point& location,
		const Color& maskColor = Color::White) override;
	virtual void drawTexture(Texture& texture, const Point& location,
		const Rectangle& sliceRectangle,
		const Color& maskColor = Color::White) override;
	virtual void drawTexture(Texture& texture, f32 x, f32 y,
		const Color& maskColor = Color::White) override;
	virtual void drawTexture(Texture& texture, f32 x, f32 y,
		const Rectangle& sliceRectangle,
		const Color& maskColor = Color::White) override;
	virtual void drawTexture(Texture& texture, const PointF& location,
		const Color& maskColor = Color::White) override;
	virtual void drawTexture(Texture& texture, const PointF& location,
		const Rectangle& sliceRectangle,
		const Color& maskColor = Color::White) override;
};


#endif