#include "Window.h"

#include "CodeAdapter\SharedObject.h"

#include "CodeAdapter\Size.h"
#include "CodeAdapter\Color.h"
#include "CodeAdapter\String.h"




Window::Window(SharedObject<sf::RenderWindow>& sharedWin)
	: m_sharedWin(sharedWin)
{

}


Window::~Window()
{

}

//###########################################################################

void Window::create(const Size& size, const String& title)
{
	m_win.create(sf::VideoMode(size.width, size.height),
		title.getStr());
}


void Window::exit()
{
	m_win.close();
}

//--------------------------------------------------------------------------

bool Window::isRunning() const
{
	return m_win.isOpen();
}

//###########################################################################

void Window::show()
{
	m_win.setActive(true);
}


void Window::hide()
{
	m_win.setActive(false);
}

//--------------------------------------------------------------------------

bool Window::isOpen() const
{
	return m_win.hasFocus();
}

//###########################################################################

void Window::onUpdate()
{
	sf::Event temp;
	if (m_win.pollEvent(temp))
	{
		if (temp.type == sf::Event::Closed)
			this->exit();
	}
}


void Window::beginDraw(const Color& backColor)
{
	m_win.clear(sf::Color(
		backColor.r,
		backColor.g,
		backColor.b,
		backColor.a));

	m_sharedWin.setObject(&m_win);
}


void Window::endDraw()
{
	m_win.display();
}
