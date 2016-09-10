#include "Window.h"

#include "CodeAdapter\String.h"
#include "CodeAdapter\SharedObject.h"

#include "CodeAdapter\Size.h"
#include "CodeAdapter\Color.h"

#include "CodeAdapter\WindowEvent.h"




Window::Window(SharedObject<sf::RenderWindow>& sharedWin)
	: m_sharedWin(sharedWin)
{
	
}


Window::~Window()
{

}

//###########################################################################

void Window::create(const Size& size, const String& title, bool isFullscreen)
{
	m_win.create(sf::VideoMode(size.width, size.height),
		title.getStr(),
		isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
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

bool Window::onUpdate(WindowEvent* outEvent)
{
	sf::Event newEvent;
	if (m_win.pollEvent(newEvent))
	{
		if (newEvent.type == sf::Event::Closed)
			this->exit();

		if (outEvent != nullptr)
		{
			using EventTypes = WindowEvent::Types;

			EventTypes eventType = EventTypes::Unknown;


			switch (newEvent.type)
			{
			case sf::Event::Closed:
				eventType = EventTypes::Closed;
				break;

			case sf::Event::Resized:
				eventType = EventTypes::Resized;
				outEvent->size.width = newEvent.size.width;
				outEvent->size.height = newEvent.size.height;
				break;

			case sf::Event::TextEntered:
				eventType = EventTypes::TextEntered;
				outEvent->text.unicode = newEvent.text.unicode;
				break;
			}


			outEvent->setType(eventType);
		}


		return true;
	}


	return false;
}


void Window::beginDraw(const Color& backColor)
{
	m_win.clear(sf::Color(
		backColor.r,
		backColor.g,
		backColor.b,
		backColor.a));
}


void Window::endDraw()
{
	m_win.display();
}

//###########################################################################

auto Window::getSize() const -> Size
{
	auto size = m_win.getSize();
	return Size(size.x, size.y);
}


void Window::setFramerate(int framePerSec)
{
	m_win.setFramerateLimit(framePerSec);
}


void Window::disableFramerate()
{
	m_win.setFramerateLimit(0);
}

//###########################################################################

void Window::attach()
{
	m_sharedWin.pushObject(&m_win);
}


void Window::detach()
{
	m_sharedWin.popObject();
}

