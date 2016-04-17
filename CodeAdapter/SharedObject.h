#ifndef __CA__SHARED_OBJECT_H__
#define __CA__SHARED_OBJECT_H__


#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_UTILITY


template <typename T>
class SharedObject
{
public:
	SharedObject();
	virtual ~SharedObject();


protected:
	T* m_sharedObj;


public:
	void setObject(T* obj);
	T* getObject();
	const T* getObject() const;
};


END_NAMESPACE_CA_UTILITY


#include "SharedObject.inl"


#endif