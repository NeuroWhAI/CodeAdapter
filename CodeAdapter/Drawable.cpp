#include "Drawable.h"

#include "Graphics.h"




BEGIN_NAMESPACE_CA_DRAWING


Drawable::Drawable()
	: m_visible(true)
{

}


Drawable::~Drawable()
{

}

//###########################################################################

void Drawable::draw(Graphics& g, const Transform& parentTransform)
{
	if (m_visible)
	{
		Transform combined = parentTransform;
		combined.addTransform(transform);

		auto backup = g.getTransform();

		g.setTransform(combined);

		onDraw(g, combined);

		g.setTransform(backup);
	}
}

//###########################################################################

void Drawable::setVisible(bool visible)
{
	m_visible = visible;
}


bool Drawable::isVisible() const
{
	return m_visible;
}


END_NAMESPACE_CA_DRAWING

