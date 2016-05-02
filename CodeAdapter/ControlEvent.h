#ifndef __CA__CONTROL_EVENT_H__
#define __CA__CONTROL_EVENT_H__


#include <functional>

#include "BasicDeclaration.h"

#include "Keys.h"




BEGIN_NAMESPACE_CA_UI


class EventArgs
{
public:
	EventArgs();
	virtual ~EventArgs();
};


class TouchEventArgs : public EventArgs
{
public:
	TouchEventArgs();
	TouchEventArgs(i32 x, i32 y);
	virtual ~TouchEventArgs();


public:
	i32 x, y;
};


class KeyEventArgs : public EventArgs
{
public:
	KeyEventArgs();
	explicit KeyEventArgs(System::Keys key);
	virtual ~KeyEventArgs();


public:
	System::Keys key;
};

//############################################################

using EventHandler = std::function<void(const EventArgs&)>;
using TouchEventHandler = std::function<void(const TouchEventArgs&)>;
using KeyEventHandler = std::function<void(const KeyEventArgs&)>;


END_NAMESPACE_CA_UI


#endif