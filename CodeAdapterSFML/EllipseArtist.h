#ifndef __CA_SFML__ELLIPSE_ARTIST_H__
#define __CA_SFML__ELLIPSE_ARTIST_H__


#include "CodeAdapter\EllipseArtist.h"

#include "SFML\Graphics.hpp"




class EllipseArtist : public CodeAdapter::Drawing::EllipseArtist
{
public:
	template <typename T>
	using SharedObject = CodeAdapter::Utility::SharedObject<T>;

	using Color = CodeAdapter::Drawing::Color;
	using Point = CodeAdapter::Drawing::Point;
	using PointF = CodeAdapter::Drawing::PointF;
	using Size = CodeAdapter::Drawing::Size;
	using SizeF = CodeAdapter::Drawing::SizeF;
	using Rectangle = CodeAdapter::Drawing::Rectangle;
	using RectangleF = CodeAdapter::Drawing::RectangleF;


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
	virtual void beginDrawEllipse(float thickness) override;
	virtual void endDrawEllipse() override;
	virtual void drawEllipse(int x, int y, int width, int height, const Color& color) override;
	virtual void drawEllipse(const Point& location, const Size& size, const Color& color) override;
	virtual void drawEllipse(const Rectangle& rectangle, const Color& color) override;
	virtual void drawEllipse(float x, float y, float width, float height, const Color& color) override;
	virtual void drawEllipse(const PointF& location, const SizeF& size, const Color& color) override;
	virtual void drawEllipse(const RectangleF& rectangle, const Color& color) override;

	virtual void beginFillEllipse() override;
	virtual void endFillEllipse() override;
	virtual void fillEllipse(int x, int y, int width, int height, const Color& color) override;
	virtual void fillEllipse(const Point& location, const Size& size, const Color& color) override;
	virtual void fillEllipse(const Rectangle& rectangle, const Color& color) override;
	virtual void fillEllipse(float x, float y, float width, float height, const Color& color) override;
	virtual void fillEllipse(const PointF& location, const SizeF& size, const Color& color) override;
	virtual void fillEllipse(const RectangleF& rectangle, const Color& color) override;
};


#endif