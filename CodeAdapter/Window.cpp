#include "Window.h"

#include "UsingSharable.h"

#include "String.h"

#include "Point.h"
#include "Size.h"
#include "Color.h"
#include "Panel.h"
#include "Graphics.h"




BEGIN_NAMESPACE_CA_DRAWING


Window::Window()
	: m_graphics(std::make_shared<Graphics>())
{

}


Window::~Window()
{

}

//###########################################################################

bool Window::update(WindowEvent* outEvent)
{
	for (auto& panel : m_panelList)
	{
		panel->update(*this);
	}


	m_latestEvent.setType(WindowEvent::Types::Unknown);

	bool hadEvent = onUpdate(&m_latestEvent);

	if (outEvent != nullptr)
	{
		*outEvent = m_latestEvent;
	}


	return hadEvent;
}


void Window::draw(const Color& backColor)
{
	Utility::UsingSharable shareWin(*this);

	beginDraw(backColor);

	for (auto& panel : m_panelList)
	{
		panel->draw(*m_graphics);
	}

	endDraw();
}

//###########################################################################

bool Window::addPanel(std::shared_ptr<Panel> panel)
{
	for (const auto& panelItem : m_panelList)
	{
		if (panelItem == panel)
		{
			return false;
		}
	}


	m_panelList.emplace_back(panel);


	return true;
}


bool Window::removePanel(std::shared_ptr<const Panel> panel)
{
	usize index = 0;
	for (const auto& panelItem : m_panelList)
	{
		if (panelItem == panel)
		{
			m_panelList.erase(m_panelList.begin() + index);

			return true;
		}

		++index;
	}


	return false;
}

//###########################################################################

bool Window::checkLatestEvent(WindowEvent::Types type) const
{
	return (type == m_latestEvent.getType());
}


auto Window::getLatestEvent() const -> WindowEvent
{
	return m_latestEvent;
}


END_NAMESPACE_CA_DRAWING

