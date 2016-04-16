#ifndef __CA__RECTANGLE_ARTIST_H__
#define __CA__RECTANGLE_ARTIST_H__


#include "Definition.h"
#include "CAType.h"

#include "Artist.h"




BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
class PointT;
using Point = PointT<i32>;
using PointF = PointT<f32>;

template <typename T>
class SizeT;
using Size = SizeT<i32>;
using SizeF = SizeT<f32>;

template <typename T>
class RectangleT;
using Rectangle = RectangleT<i32>;
using RectangleF = RectangleT<f32>;

template <typename T>
class ColorT;
using Color = ColorT<i32>;
using ColorF = ColorT<f32>;


class RectangleArtist : public Artist
{
public:
	RectangleArtist();
	virtual ~RectangleArtist();


public:
	virtual void beginDrawRectangle(float thickness) = 0;
	virtual void endDrawRectangle() = 0;
	virtual void drawRectangle(int x, int y, int width, int height, const Color& color) = 0;
	virtual void drawRectangle(const Point& location, const Size& size, const Color& color) = 0;
	virtual void drawRectangle(const Rectangle& rectangle, const Color& color) = 0;
	virtual void drawRectangle(float x, float y, float width, float height, const Color& color) = 0;
	virtual void drawRectangle(const PointF& location, const SizeF& size, const Color& color) = 0;
	virtual void drawRectangle(const RectangleF& rectangle, const Color& color) = 0;

	virtual void beginFillRectangle() = 0;
	virtual void endFillRectangle() = 0;
	virtual void fillRectangle(int x, int y, int width, int height, const Color& color) = 0;
	virtual void fillRectangle(const Point& location, const Size& size, const Color& color) = 0;
	virtual void fillRectangle(const Rectangle& rectangle, const Color& color) = 0;
	virtual void fillRectangle(float x, float y, float width, float height, const Color& color) = 0;
	virtual void fillRectangle(const PointF& location, const SizeF& size, const Color& color) = 0;
	virtual void fillRectangle(const RectangleF& rectangle, const Color& color) = 0;
};


END_NAMESPACE_CA_DRAWING


#endif