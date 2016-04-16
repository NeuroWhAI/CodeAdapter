#ifndef __CA__GRAPHICS_H__
#define __CA__GRAPHICS_H__


#include <memory>

#include "Definition.h"
#include "CAType.h"




BEGIN_NAMESPACE_CA_DRAWING


class TextArtist;
class RectangleArtist;


class Graphics
{
public:
	Graphics();
	virtual ~Graphics();


public:
	std::shared_ptr<TextArtist> textArtist;
	std::shared_ptr<RectangleArtist> rectangleArtist;
};


END_NAMESPACE_CA_DRAWING


#endif