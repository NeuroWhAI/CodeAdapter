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
	std::shared_ptr<TextArtist> textArtist;
	std::shared_ptr<RectangleArtist> rectangleArtist;
	std::shared_ptr<EllipseArtist> ellipseArtist;
};


END_NAMESPACE_CA_DRAWING


#endif