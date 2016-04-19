#ifndef __CA_SFML__ELLIPSE_ARTIST_H__
#define __CA_SFML__ELLIPSE_ARTIST_H__


#include "CodeAdapter\EllipseArtist.h"

#include "SFML\Graphics.hpp"




class EllipseArtist : public CodeAdapter::Drawing::EllipseArtist
{
public:
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
	EllipseArtist(SharedObject<sf::RenderWindow>& sharedWin);
	virtual ~EllipseArtist();


protected:
	SharedObject<sf::RenderWindow>& m_sharedWin;
	sf::RenderStates m_renderStates;


protected:
	sf::CircleShape m_drawCircle;
	sf::CircleShape m_fillCircle;


protected:
	void updateRenderTransform();


public:
	virtual void beginDrawEllipse(f32 thickness) override;
	virtual void endDrawEllipse() override;
	virtual void drawEllipse(i32 x, i32 y, i32 width, i32 height, const Color& color) override;
	virtual void drawEllipse(const Point& location, const Size& size, const Color& color) override;
	virtual void drawEllipse(const Rectangle& rectangle, const Color& color) override;
	virtual void drawEllipse(f32 x, f32 y, f32 width, f32 height, const Color& color) override;
	virtual void drawEllipse(const PointF& location, const SizeF& size, const Color& color) override;
	virtual void drawEllipse(const RectangleF& rectangle, const Color& color) override;

	virtual void beginFillEllipse() override;
	virtual void endFillEllipse() override;
	virtual void fillEllipse(i32 x, i32 y, i32 width, i32 height, const Color& color) override;
	virtual void fillEllipse(const Point& location, const Size& size, const Color& color) override;
	virtual void fillEllipse(const Rectangle& rectangle, const Color& color) override;
	virtual void fillEllipse(f32 x, f32 y, f32 width, f32 height, const Color& color) override;
	virtual void fillEllipse(const PointF& location, const SizeF& size, const Color& color) override;
	virtual void fillEllipse(const RectangleF& rectangle, const Color& color) override;
};


#endif