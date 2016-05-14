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
	: KeyEventArgs(System::Keys::Unknown)
{

}


KeyEventArgs::KeyEventArgs(System::Keys key)
	: KeyEventArgs(key, false, false, false)
{

}


KeyEventArgs::KeyEventArgs(System::Keys key, bool ctrl, bool shift, bool alt)
	: key(key)
	, ctrl(ctrl)
	, shift(shift)
	, alt(alt)
{

}


KeyEventArgs::~KeyEventArgs()
{

}


END_NAMESPACE_CA_UI

