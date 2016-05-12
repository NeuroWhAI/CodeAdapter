#ifndef __CA__EVENT_H__
#define __CA__EVENT_H__


#include <functional>
#include <vector>

#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_UTILITY


template <typename... ArgTypes>
class Event
{
public:
	using DelegateType = std::function<void(ArgTypes...)>;


public:
	Event();
	Event(const DelegateType& func);
	virtual ~Event();


protected:
	std::vector<DelegateType> m_funcList;
	std::vector<const DelegateType*> m_ptrList;


public:
	void clear();
	void operator() (ArgTypes&&... args);
	Event<ArgTypes...>& operator+= (const DelegateType& func);
	Event<ArgTypes...>& operator+= (const DelegateType&& func);
	Event<ArgTypes...>& operator-= (const DelegateType& func);
	Event<ArgTypes...>& operator+= (const Event<ArgTypes...>& otherEvent);
	Event<ArgTypes...>& operator-= (const Event<ArgTypes...>& otherEvent);
	Event<ArgTypes...>& operator= (const DelegateType& func);
	operator bool() const;
};


END_NAMESPACE_CA_UTILITY


#include "Event.inl"


#endif