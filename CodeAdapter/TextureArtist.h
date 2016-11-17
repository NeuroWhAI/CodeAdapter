#ifndef __CA__TEXTURE_ARTIST_H__
#define __CA__TEXTURE_ARTIST_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Artist.h"

#include "Color.h"
#include "Rectangle.h"




BEGIN_NAMESPACE_CA_DRAWING


class TextureArtist : public Artist
{
public:
	using Ptr = std::shared_ptr<TextureArtist>;


public:
	TextureArtist();
	virtual ~TextureArtist();


public:
	virtual void beginDrawTexture() = 0;
	virtual void endDrawTexture() = 0;
	virtual void drawTexture(Texture& texture, i32 x, i32 y,
		const Color& maskColor = Color::White) = 0;
	virtual void drawTexture(Texture& texture, i32 x, i32 y,
		const Rectangle& sliceRectangle,
		const Color& maskColor = Color::White) = 0;
	virtual void drawTexture(Texture& texture, const Point& location,
		const Color& maskColor = Color::White) = 0;
	virtual void drawTexture(Texture& texture, const Point& location,
		const Rectangle& sliceRectangle,
		const Color& maskColor = Color::White) = 0;
	virtual void drawTexture(Texture& texture, f32 x, f32 y,
		const Color& maskColor = Color::White) = 0;
	virtual void drawTexture(Texture& texture, f32 x, f32 y,
		const Rectangle& sliceRectangle,
		const Color& maskColor = Color::White) = 0;
	virtual void drawTexture(Texture& texture, const PointF& location,
		const Color& maskColor = Color::White) = 0;
	virtual void drawTexture(Texture& texture, const PointF& location,
		const Rectangle& sliceRectangle,
		const Color& maskColor = Color::White) = 0;
};


END_NAMESPACE_CA_DRAWING


#endif