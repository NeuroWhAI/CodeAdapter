#include "ControlEvent.h"




BEGIN_NAMESPACE_CA_UI


EventArgs::EventArgs()
{

}


EventArgs::~EventArgs()
{

}

//###########################################################################

TouchEventArgs::TouchEventArgs()
	: x(0)
	, y(0)
{

}


TouchEventArgs::TouchEventArgs(i32 x, i32 y)
	: x(x)
	, y(y)
{

}


TouchEventArgs::~TouchEventArgs()
{

}

//###########################################################################

KeyEventArgs::KeyEventArgs()
	: key(System::Keys::Unknown)
{

}


KeyEventArgs::KeyEventArgs(System::Keys key)
	: key(key)
{

}


KeyEventArgs::~KeyEventArgs()
{

}


END_NAMESPACE_CA_UI

