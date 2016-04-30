#include "SingletonWrapper.h"




BEGIN_NAMESPACE_CA_UTILITY


template <typename T>
SingletonWrapper<T>::SingletonWrapper()
{

}


template <typename T>
SingletonWrapper<T>::~SingletonWrapper()
{

}

//###########################################################################

template <typename T>
T* SingletonWrapper<T>::operator->()
{
	return T::getInstance();
}


template <typename T>
const T* SingletonWrapper<T>::operator->() const
{
	return T::getInstance();
}


END_NAMESPACE_CA_UTILITY

