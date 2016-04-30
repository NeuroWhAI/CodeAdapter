#include "EasyCA.h"




template <typename T>
void initializeCA()
{
	Factory::initializeInstance<T>();
}

//###########################################################################

template <typename T>
std::shared_ptr<T> canew()
{
	return std::make_shared<T>();
}

template <typename T, typename... Args>
std::shared_ptr<T> canew(Args&... args)
{
	return std::make_shared<T>(args...);
}

template <typename T, typename... Args>
std::shared_ptr<T> canew(Args... args)
{
	return std::make_shared<T>(args...);
}

