#ifndef __CA_SFML__RECTANGLE_ARTIST_H__
#define __CA_SFML__RECTANGLE_ARTIST_H__


#include "CodeAdapter\RectangleArtist.h"

#include "SFML\Graphics.hpp"




class RectangleArtist : public CodeAdapter::Drawing::RectangleArtist
{
private:
	USING_CA(i32);
	USING_CA(f32);

	USING_CA_UTILITY_T(SharedObject, T);

	USING_CA_DRAWING(Color);
	USING_CA_DRAWING(Point);
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(Size);
	USING_CA_DRAWING(SizeF);
	USING_CA_DRAWING(Rectangle);
	USING_CA_DRAWING(RectangleF);


public:
	explicit RectangleArtist(SharedObject<sf::RenderWindow>& sharedWin);
	virtual ~RectangleArtist();


protected:
	SharedObject<sf::RenderWindow>& m_sharedWin;
	sf::RenderStates m_renderStates;


protected:
	sf::RectangleShape m_drawRect;
	sf::RectangleShape m_fillRect;


protected:
	void updateRenderTransform();


public:
	virtual void beginDrawRectangle(f32 thickness) override;
	virtual void endDrawRectangle() override;
	virtual void drawRectangle(i32 x, i32 y, i32 width, i32 height, const Color& color) override;
	virtual void drawRectangle(const Point& location, const Size& size, const Color& color) override;
	virtual void drawRectangle(const Rectangle& rectangle, const Color& color) override;
	virtual void drawRectangle(f32 x, f32 y, f32 width, f32 height, const Color& color) override;
	virtual void drawRectangle(const PointF& location, const SizeF& size, const Color& color) override;
	virtual void drawRectangle(const RectangleF& rectangle, const Color& color) override;

	virtual void beginFillRectangle() override;
	virtual void endFillRectangle() override;
	virtual void fillRectangle(i32 x, i32 y, i32 width, i32 height, const Color& color) override;
	virtual void fillRectangle(const Point& location, const Size& size, const Color& color) override;
	virtual void fillRectangle(const Rectangle& rectangle, const Color& color) override;
	virtual void fillRectangle(f32 x, f32 y, f32 width, f32 height, const Color& color) override;
	virtual void fillRectangle(const PointF& location, const SizeF& size, const Color& color) override;
	virtual void fillRectangle(const RectangleF& rectangle, const Color& color) override;
};


#endif