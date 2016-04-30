#ifndef __CA__SHARED_OBJECT_H__
#define __CA__SHARED_OBJECT_H__


#include <stack>

#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_UTILITY


template <typename T>
class SharedObject
{
public:
	SharedObject();
	virtual ~SharedObject();


protected:
	std::stack<T*> m_sharedObjStack;


public:
	void pushObject(T* obj);
	T* getObject();
	const T* getObject() const;
	T* popObject();
	const T* popObject() const;
};


END_NAMESPACE_CA_UTILITY


#include "SharedObject.inl"


#endif