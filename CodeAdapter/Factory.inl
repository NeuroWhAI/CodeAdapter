#include "Factory.h"




BEGIN_NAMESPACE_CA


template <typename T>
void Factory::initializeInstance()
{
	if (s_pInstance != nullptr)
		delete s_pInstance;

	s_pInstance = new T();
}


END_NAMESPACE_CA

