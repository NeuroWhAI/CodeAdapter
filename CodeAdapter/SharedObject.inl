#include "SharedObject.h"




BEGIN_NAMESPACE_CA_UTILITY


template <typename T>
SharedObject<T>::SharedObject()
{
	m_sharedObjStack.push(nullptr);
}


template <typename T>
SharedObject<T>::~SharedObject()
{

}

//###########################################################################

template <typename T>
void SharedObject<T>::pushObject(T* obj)
{
	m_sharedObjStack.push(obj);
}


template <typename T>
T* SharedObject<T>::getObject()
{
	return m_sharedObjStack.top();
}


template <typename T>
const T* SharedObject<T>::getObject() const
{
	return m_sharedObjStack.top();
}


template <typename T>
T* SharedObject<T>::popObject()
{
	auto topObj = m_sharedObjStack.top();
	m_sharedObjStack.pop();

	return topObj;
}


template <typename T>
const T* SharedObject<T>::popObject() const
{
	const auto topObj = m_sharedObjStack.top();
	m_sharedObjStack.pop();

	return topObj;
}


END_NAMESPACE_CA_UTILITY

