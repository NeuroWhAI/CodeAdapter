#include "WindowEvent.h"




BEGIN_NAMESPACE_CA_SYSTEM


WindowEvent::WindowEvent()
	: m_eventType(Types::Unknown)
{

}


WindowEvent::~WindowEvent()
{

}

//###########################################################################

auto WindowEvent::getType() const -> Types
{
	return m_eventType;
}


void WindowEvent::setType(Types type)
{
	m_eventType = type;
}


END_NAMESPACE_CA_SYSTEM

