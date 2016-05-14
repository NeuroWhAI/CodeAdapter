#ifndef __CA__CONTROL_EVENT_H__
#define __CA__CONTROL_EVENT_H__


#include <functional>

#include "BasicDeclaration.h"

#include "Keys.h"
#include "Event.h"




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
	KeyEventArgs(System::Keys key, bool ctrl, bool shift, bool alt);
	virtual ~KeyEventArgs();


public:
	System::Keys key;
	bool ctrl, shift, alt;
};

//############################################################

using EventHandler = Utility::Event<const EventArgs&>;
using TouchEventHandler = Utility::Event<const TouchEventArgs&>;
using KeyEventHandler = Utility::Event<const KeyEventArgs&>;


END_NAMESPACE_CA_UI


#endif