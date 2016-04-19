#ifndef __CA__RECTANGLE_ARTIST_H__
#define __CA__RECTANGLE_ARTIST_H__


#include "BasicDeclaration.h"

#include "Artist.h"




BEGIN_NAMESPACE_CA_DRAWING


class RectangleArtist : public Artist
{
public:
	RectangleArtist();
	virtual ~RectangleArtist();


public:
	virtual void beginDrawRectangle(f32 thickness) = 0;
	virtual void endDrawRectangle() = 0;
	virtual void drawRectangle(i32 x, i32 y, i32 width, i32 height, const Color& color) = 0;
	virtual void drawRectangle(const Point& location, const Size& size, const Color& color) = 0;
	virtual void drawRectangle(const Rectangle& rectangle, const Color& color) = 0;
	virtual void drawRectangle(f32 x, f32 y, f32 width, f32 height, const Color& color) = 0;
	virtual void drawRectangle(const PointF& location, const SizeF& size, const Color& color) = 0;
	virtual void drawRectangle(const RectangleF& rectangle, const Color& color) = 0;

	virtual void beginFillRectangle() = 0;
	virtual void endFillRectangle() = 0;
	virtual void fillRectangle(i32 x, i32 y, i32 width, i32 height, const Color& color) = 0;
	virtual void fillRectangle(const Point& location, const Size& size, const Color& color) = 0;
	virtual void fillRectangle(const Rectangle& rectangle, const Color& color) = 0;
	virtual void fillRectangle(f32 x, f32 y, f32 width, f32 height, const Color& color) = 0;
	virtual void fillRectangle(const PointF& location, const SizeF& size, const Color& color) = 0;
	virtual void fillRectangle(const RectangleF& rectangle, const Color& color) = 0;
};


END_NAMESPACE_CA_DRAWING


#endif