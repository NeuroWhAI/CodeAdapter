#include "Panel.h"

#include "CodeAdapter\SharedObject.h"




Panel::Panel(SharedObject<sf::RenderWindow>& sharedWin)
	: m_sharedWin(sharedWin)
{

}


Panel::~Panel()
{

}

//###########################################################################

void Panel::beginDraw(const Transform& parentTransform)
{
	auto win = m_sharedWin.getObject();
	auto winSize = win->getSize();

	m_view.setViewport(sf::FloatRect(
		parentTransform.position.x / winSize.x,
		parentTransform.position.y / winSize.y,
		size.width / winSize.x,
		size.height / winSize.y));
	m_view.reset(sf::FloatRect(
		parentTransform.position.x,
		parentTransform.position.y,
		size.width,
		size.height));

	win->setView(m_view);
}


void Panel::endDraw()
{
	auto win = m_sharedWin.getObject();
	win->setView(win->getDefaultView());
}

