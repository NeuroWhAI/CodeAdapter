#include "DrawableTexture.h"

#include "Graphics.h"
#include "Transform.h"

#include "TextureArtist.h"




BEGIN_NAMESPACE_CA_DRAWING


DrawableTexture::DrawableTexture()
	: color(Color::White)
{

}


DrawableTexture::~DrawableTexture()
{

}

//###########################################################################

void DrawableTexture::onDraw(Graphics& g, const Transform& parentTransform)
{
	if (!m_texture.expired())
	{
		auto& artist = g.textureArtist;


		artist->initialize(parentTransform);


		auto texture = m_texture.lock();
		artist->beginDrawTexture();

		artist->drawTexture(*texture, location, color);

		artist->endDrawTexture();
	}
}

//###########################################################################

void DrawableTexture::setTexture(std::weak_ptr<Texture> texture)
{
	m_texture = texture;
}


END_NAMESPACE_CA_DRAWING

