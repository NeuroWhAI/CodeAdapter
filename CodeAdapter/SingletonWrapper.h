#ifndef __CA__CLEAN_CODE_ADAPTER_H__
#define __CA__CLEAN_CODE_ADAPTER_H__


#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_UTILITY


template <typename T>
class SingletonWrapper
{
public:
	SingletonWrapper();
	SingletonWrapper(const SingletonWrapper&) = delete;
	virtual ~SingletonWrapper();


public:
	inline T* operator->();
	inline const T* operator->() const;
};


END_NAMESPACE_CA_UTILITY


#include "SingletonWrapper.inl"


#endif