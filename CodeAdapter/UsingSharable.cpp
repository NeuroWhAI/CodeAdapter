#include "UsingSharable.h"

#include "Sharable.h"




BEGIN_NAMESPACE_CA_UTILITY


UsingSharable::UsingSharable(Sharable& target)
	: m_target(target)
{
	m_target.attach();
}


UsingSharable::~UsingSharable()
{
	m_target.detach();
}


END_NAMESPACE_CA_UTILITY

