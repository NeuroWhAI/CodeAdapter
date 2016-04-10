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
		throw std::exception("���丮 �ν��Ͻ��� �ʱ�ȭ���� �ʾҽ��ϴ�.");
#endif

	return s_pInstance;
}


END_NAMESPACE_CA

