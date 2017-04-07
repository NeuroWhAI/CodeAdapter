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


const Transform& Artist::getTransform() const
{
	return m_transform;
}


END_NAMESPACE_CA_DRAWING

