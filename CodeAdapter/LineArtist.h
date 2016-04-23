#ifndef __CA__LINE_ARTIST_H__
#define __CA__LINE_ARTIST_H__


#include "BasicDeclaration.h"

#include "Artist.h"




BEGIN_NAMESPACE_CA_DRAWING


class LineArtist : public Artist
{
public:
	LineArtist();
	virtual ~LineArtist();

	
public:
	virtual void beginDrawLine(f32 thickness) = 0;
	virtual void endDrawLine() = 0;
	virtual void drawLine(i32 x1, i32 y1, i32 x2, i32 y2, const Color& color) = 0;
	virtual void drawLine(const Point& point1, const Point& point2, const Color& color) = 0;
	virtual void drawLine(f32 x1, f32 y1, f32 x2, f32 y2, const Color& color) = 0;
	virtual void drawLine(const PointF& point1, const PointF& point2, const Color& color) = 0;
};


END_NAMESPACE_CA_DRAWING


#endif