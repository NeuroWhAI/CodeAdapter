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


public:
	i32 x, y;
};


class KeyEventArgs : public EventArgs
{
public:
	KeyEventArgs();
	explicit KeyEventArgs(System::Keys key);
	KeyEventArgs(System::Keys key, bool ctrl, bool shift, bool alt);


public:
	System::Keys key;
	bool ctrl, shift, alt;
};


template <typename T>
class ValueTEventArgs : public EventArgs
{
public:
	ValueTEventArgs();
	explicit ValueTEventArgs(const T& value);


public:
	T value;
};
using ValueEventArgs = ValueTEventArgs<i32>;
using ValueFEventArgs = ValueTEventArgs<f32>;

//############################################################

using EventHandler = Utility::Event<const EventArgs&>;
using TouchEventHandler = Utility::Event<const TouchEventArgs&>;
using KeyEventHandler = Utility::Event<const KeyEventArgs&>;
using ValueEventHandler = Utility::Event<const ValueEventArgs&>;
using ValueFEventHandler = Utility::Event<const ValueFEventArgs&>;


END_NAMESPACE_CA_UI


#include "ControlEvent.inl"


#endif