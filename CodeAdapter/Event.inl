#include "Event.h"




BEGIN_NAMESPACE_CA_UTILITY


template <typename... ArgTypes>
Event<ArgTypes...>::Event()
{

}


template <typename... ArgTypes>
Event<ArgTypes...>::Event(const DelegateType& func)
{
	this->operator+=(func);
}


template <typename... ArgTypes>
Event<ArgTypes...>::~Event()
{

}

//###########################################################################

template <typename... ArgTypes>
void Event<ArgTypes...>::clear()
{
	m_funcList.clear();
}


template <typename... ArgTypes>
void Event<ArgTypes...>::operator() (ArgTypes&&... args)
{
	for (auto& func : m_funcList)
	{
		func(args...);
	}
}


template <typename... ArgTypes>
Event<ArgTypes...>&
Event<ArgTypes...>::operator+= (const DelegateType& func)
{
	if (func)
	{
		m_funcList.emplace_back(func);
	}

	
	return *this;
}


template <typename... ArgTypes>
Event<ArgTypes...>&
Event<ArgTypes...>::operator= (const DelegateType& func)
{
	this->clear();

	if (func)
	{
		m_funcList.emplace_back(func);
	}


	return *this;
}


template <typename... ArgTypes>
Event<ArgTypes...>::operator bool() const
{
	return (m_funcList.size() > 0);
}


END_NAMESPACE_CA_UTILITY

