#ifndef __CA__ELLIPSE_ARTIST_H__
#define __CA__ELLIPSE_ARTIST_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Artist.h"




BEGIN_NAMESPACE_CA_DRAWING


class EllipseArtist : public Artist
{
public:
	using Ptr = std::shared_ptr<EllipseArtist>;


public:
	EllipseArtist();
	virtual ~EllipseArtist();


public:
	virtual void beginDrawEllipse(f32 thickness) = 0;
	virtual void endDrawEllipse() = 0;
	virtual void drawEllipse(i32 x, i32 y, i32 width, i32 height, const Color& color) = 0;
	virtual void drawEllipse(const Point& location, const Size& size, const Color& color) = 0;
	virtual void drawEllipse(const Rectangle& rectangle, const Color& color) = 0;
	virtual void drawEllipse(f32 x, f32 y, f32 width, f32 height, const Color& color) = 0;
	virtual void drawEllipse(const PointF& location, const SizeF& size, const Color& color) = 0;
	virtual void drawEllipse(const RectangleF& rectangle, const Color& color) = 0;

	virtual void beginFillEllipse() = 0;
	virtual void endFillEllipse() = 0;
	virtual void fillEllipse(i32 x, i32 y, i32 width, i32 height, const Color& color) = 0;
	virtual void fillEllipse(const Point& location, const Size& size, const Color& color) = 0;
	virtual void fillEllipse(const Rectangle& rectangle, const Color& color) = 0;
	virtual void fillEllipse(f32 x, f32 y, f32 width, f32 height, const Color& color) = 0;
	virtual void fillEllipse(const PointF& location, const SizeF& size, const Color& color) = 0;
	virtual void fillEllipse(const RectangleF& rectangle, const Color& color) = 0;
};


END_NAMESPACE_CA_DRAWING


#endif