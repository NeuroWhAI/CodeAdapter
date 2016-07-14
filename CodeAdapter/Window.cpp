#include "Window.h"

#include "UsingSharable.h"

#include "String.h"

#include "Point.h"
#include "Size.h"
#include "Color.h"
#include "Graphics.h"
#include "Transform.h"

#include "SceneManager.h"




BEGIN_NAMESPACE_CA_DRAWING


Window::Window()
	: m_graphics(std::make_shared<Graphics>())
	, m_sceneManager(nullptr)
{

}


Window::~Window()
{

}

//###########################################################################

bool Window::update(WindowEvent* outEvent)
{
	if (m_sceneManager)
	{
		m_sceneManager->update(*this);
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

	if (m_sceneManager)
	{
		m_sceneManager->draw(*m_graphics);
	}

	m_graphics->setTransform(Transform::Identity);

	endDraw();
}

//###########################################################################

void Window::setSceneManager(std::shared_ptr<SceneManager> mgr)
{
	m_sceneManager = mgr;
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

