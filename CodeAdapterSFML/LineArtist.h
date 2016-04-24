#ifndef __CA_SFML__LINE_ARTIST_H__
#define __CA_SFML__LINE_ARTIST_H__


#include "CodeAdapter\LineArtist.h"

#include "SFML\Graphics.hpp"




class LineArtist : public CodeAdapter::Drawing::LineArtist
{
private:
	USING_CA(i32);
	USING_CA(f32);
	USING_CA(usize);

	USING_CA_UTILITY_T(SharedObject, T);

	USING_CA_DRAWING(Color);
	USING_CA_DRAWING(Point);
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(VectorF);


public:
	explicit LineArtist(SharedObject<sf::RenderWindow>& sharedWin);
	virtual ~LineArtist();


protected:
	SharedObject<sf::RenderWindow>& m_sharedWin;
	sf::RenderStates m_renderStates;


protected:
	f32 m_thickness;


protected:
	void updateRenderTransform();


public:
	virtual void beginDrawLine(f32 thickness) override;
	virtual void endDrawLine() override;
	virtual void drawLine(i32 x1, i32 y1, i32 x2, i32 y2, const Color& color) override;
	virtual void drawLine(const Point& point1, const Point& point2, const Color& color) override;
	virtual void drawLine(f32 x1, f32 y1, f32 x2, f32 y2, const Color& color) override;
	virtual void drawLine(const PointF& point1, const PointF& point2, const Color& color) override;
};


#endif