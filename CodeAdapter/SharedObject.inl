#include "SharedObject.h"




BEGIN_NAMESPACE_CA_UTILITY


template <typename T>
SharedObject<T>::SharedObject()
	: m_sharedObj(nullptr)
{

}


template <typename T>
SharedObject<T>::~SharedObject()
{

}

//###########################################################################

template <typename T>
void SharedObject<T>::setObject(T* obj)
{
	m_sharedObj = obj;
}


template <typename T>
T* SharedObject<T>::getObject()
{
	return m_sharedObj;
}


template <typename T>
const T* SharedObject<T>::getObject() const
{
	return m_sharedObj;
}


END_NAMESPACE_CA_UTILITY

