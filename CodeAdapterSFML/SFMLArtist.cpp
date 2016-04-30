#include "SFMLArtist.h"

#include "CodeAdapter\Transform.h"




SFMLArtist::SFMLArtist()
	: m_renderStates(sf::RenderStates::Default)
{

}


SFMLArtist::~SFMLArtist()
{

}

//###########################################################################

void SFMLArtist::updateRenderTransform(const CodeAdapter::Drawing::Transform& transform)
{
	m_renderStates.transform.translate(transform.position.x,
		transform.position.y);
	m_renderStates.transform.rotate(transform.angle);
	m_renderStates.transform.scale(transform.scale.x,
		transform.scale.y);
}

