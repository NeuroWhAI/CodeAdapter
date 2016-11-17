#ifndef __CA__GRAPHICS_H__
#define __CA__GRAPHICS_H__


#include <memory>

#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_DRAWING


class Graphics
{
public:
	Graphics();
	virtual ~Graphics();


public:
	TextArtistPtr textArtist;
	RectangleArtistPtr rectangleArtist;
	EllipseArtistPtr ellipseArtist;
	LineArtistPtr lineArtist;
	TextureArtistPtr textureArtist;


public:
	void setTransform(const Transform& transform);
};


END_NAMESPACE_CA_DRAWING


#endif