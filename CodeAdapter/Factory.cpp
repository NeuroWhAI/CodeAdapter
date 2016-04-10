#include "Factory.h"




BEGIN_NAMESPACE_CA


Factory::Factory()
{

}


Factory::~Factory()
{

}

//###########################################################################

Factory* Factory::s_pInstance = nullptr;
Factory::CleanUp Factory::s_cleaner;

//###########################################################################

Factory* Factory::getInstance()
{
#ifdef _DEBUG
	if (s_pInstance == nullptr)
		throw std::exception("팩토리 인스턴스가 초기화되지 않았습니다.");
#endif

	return s_pInstance;
}


END_NAMESPACE_CA

