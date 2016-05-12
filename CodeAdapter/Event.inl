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
	m_ptrList.clear();
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
		m_ptrList.emplace_back(&func);
	}

	
	return *this;
}


template <typename... ArgTypes>
Event<ArgTypes...>&
Event<ArgTypes...>::operator+= (const DelegateType&& func)
{
	if (func)
	{
		m_funcList.emplace_back(func);
		m_ptrList.emplace_back(nullptr);

		// func�� �� �Ҹ��� �������̹Ƿ� �ּҰ��� �����ص� �ʿ䰡 ����.
		// �� �Լ��� ȣ��Ǵ� ���� ���ٽ��� �ٷ� �������� �߰ų�
		// std::function<T> ��ü�� �ƴ�����
		// �ӽð�ü�� ���ؼ� �Ϲ������� ��ȯ�Ǵ� �͵��� ���ڷ� ���� ����̴�.
	}


	return *this;
}


template <typename... ArgTypes>
Event<ArgTypes...>&
Event<ArgTypes...>::operator-= (const DelegateType& func)
{
	decltype(m_ptrList.size()) index = 0;

	for (const auto& ptr : m_ptrList)
	{
		if (&func == ptr)
		{
			m_funcList.erase(m_funcList.begin() + index);
			m_ptrList.erase(m_ptrList.begin() + index);

			break;
		}

		++index;
	}


	return *this;
}


template <typename... ArgTypes>
Event<ArgTypes...>&
Event<ArgTypes...>::operator+= (const Event<ArgTypes...>& otherEvent)
{
	for (const auto& func : otherEvent.m_funcList)
	{
		m_funcList.emplace_back(func);
	}

	for (const auto& ptr : otherEvent.m_ptrList)
	{
		m_ptrList.emplace_back(ptr);
	}


	return *this;
}


template <typename... ArgTypes>
Event<ArgTypes...>&
Event<ArgTypes...>::operator-= (const Event<ArgTypes...>& otherEvent)
{
	for (const auto& targetPtr : otherEvent.m_ptrList)
	{
		decltype(m_ptrList.size()) index = 0;

		for (const auto& ptr : m_ptrList)
		{
			if (targetPtr == ptr)
			{
				m_funcList.erase(m_funcList.begin() + index);
				m_ptrList.erase(m_ptrList.begin() + index);

				break;
			}

			++index;
		}
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
		m_ptrList.emplace_back(&func);
	}


	return *this;
}


template <typename... ArgTypes>
Event<ArgTypes...>::operator bool() const
{
	return (m_funcList.size() > 0);
}


END_NAMESPACE_CA_UTILITY

