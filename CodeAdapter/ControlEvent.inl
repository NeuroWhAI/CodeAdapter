#include "ControlEvent.h"




BEGIN_NAMESPACE_CA_UI


template <typename T>
ValueTEventArgs<T>::ValueTEventArgs()
	: value(T(0))
{

}


template <typename T>
ValueTEventArgs<T>::ValueTEventArgs(const T& value)
	: value(value)
{

}


END_NAMESPACE_CA_UI

