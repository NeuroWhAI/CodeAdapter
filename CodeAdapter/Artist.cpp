#include "Artist.h"




BEGIN_NAMESPACE_CA_DRAWING


Artist::Artist()
{

}


Artist::~Artist()
{

}

//###########################################################################

void Artist::initialize(const Transform& transform)
{
	m_transform = transform;
}


END_NAMESPACE_CA_DRAWING

