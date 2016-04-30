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

void Panel::beginDraw()
{
	auto win = m_sharedWin.getObject();
	auto winSize = win->getSize();

	m_view.setViewport(sf::FloatRect(
		transform.position.x / winSize.x,
		transform.position.y / winSize.y,
		size.width / winSize.x,
		size.height / winSize.y));
	m_view.reset(sf::FloatRect(
		transform.position.x,
		transform.position.y,
		size.width,
		size.height));

	m_oldView = &win->getView();
	win->setView(m_view);
}


void Panel::endDraw()
{
	auto win = m_sharedWin.getObject();
	win->setView(*m_oldView);
}

