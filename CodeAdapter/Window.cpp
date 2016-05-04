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

void Window::update()
{
	for (auto& panel : m_panelList)
	{
		panel->update(*this);
	}

	onUpdate();
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


END_NAMESPACE_CA_DRAWING

