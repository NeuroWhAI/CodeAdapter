#ifndef __CA_SFML__RECTANGLE_ARTIST_H__
#define __CA_SFML__RECTANGLE_ARTIST_H__


#include "CodeAdapter\RectangleArtist.h"

#include "SFML\Graphics.hpp"




BEGIN_NAMESPACE_CA_UTILITY


template <typename T>
class SharedObject;


END_NAMESPACE_CA_UTILITY


class RectangleArtist : public CodeAdapter::Drawing::RectangleArtist
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
	RectangleArtist(SharedObject<sf::RenderWindow>& sharedWin);
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
	virtual void beginDrawRectangle(float thickness) override;
	virtual void endDrawRectangle() override;
	virtual void drawRectangle(int x, int y, int width, int height, const Color& color) override;
	virtual void drawRectangle(const Point& location, const Size& size, const Color& color) override;
	virtual void drawRectangle(const Rectangle& rectangle, const Color& color) override;
	virtual void drawRectangle(float x, float y, float width, float height, const Color& color) override;
	virtual void drawRectangle(const PointF& location, const SizeF& size, const Color& color) override;
	virtual void drawRectangle(const RectangleF& rectangle, const Color& color) override;

	virtual void beginFillRectangle() override;
	virtual void endFillRectangle() override;
	virtual void fillRectangle(int x, int y, int width, int height, const Color& color) override;
	virtual void fillRectangle(const Point& location, const Size& size, const Color& color) override;
	virtual void fillRectangle(const Rectangle& rectangle, const Color& color) override;
	virtual void fillRectangle(float x, float y, float width, float height, const Color& color) override;
	virtual void fillRectangle(const PointF& location, const SizeF& size, const Color& color) override;
	virtual void fillRectangle(const RectangleF& rectangle, const Color& color) override;
};


#endif