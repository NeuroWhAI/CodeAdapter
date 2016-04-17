#ifndef __CA__ELLIPSE_ARTIST_H__
#define __CA__ELLIPSE_ARTIST_H__


#include "BasicDeclaration.h"

#include "Artist.h"




BEGIN_NAMESPACE_CA_DRAWING


class EllipseArtist : public Artist
{
public:
	EllipseArtist();
	virtual ~EllipseArtist();


public:
	virtual void beginDrawEllipse(float thickness) = 0;
	virtual void endDrawEllipse() = 0;
	virtual void drawEllipse(int x, int y, int width, int height, const Color& color) = 0;
	virtual void drawEllipse(const Point& location, const Size& size, const Color& color) = 0;
	virtual void drawEllipse(const Rectangle& rectangle, const Color& color) = 0;
	virtual void drawEllipse(float x, float y, float width, float height, const Color& color) = 0;
	virtual void drawEllipse(const PointF& location, const SizeF& size, const Color& color) = 0;
	virtual void drawEllipse(const RectangleF& rectangle, const Color& color) = 0;

	virtual void beginFillEllipse() = 0;
	virtual void endFillEllipse() = 0;
	virtual void fillEllipse(int x, int y, int width, int height, const Color& color) = 0;
	virtual void fillEllipse(const Point& location, const Size& size, const Color& color) = 0;
	virtual void fillEllipse(const Rectangle& rectangle, const Color& color) = 0;
	virtual void fillEllipse(float x, float y, float width, float height, const Color& color) = 0;
	virtual void fillEllipse(const PointF& location, const SizeF& size, const Color& color) = 0;
	virtual void fillEllipse(const RectangleF& rectangle, const Color& color) = 0;
};


END_NAMESPACE_CA_DRAWING


#endif