#include "Control.h"




BEGIN_NAMESPACE_CA_UI


Control::Control()
{

}


Control::~Control()
{

}

//###########################################################################

void Control::update(const Transform& parentTransform)
{
	// TODO: �⺻���� �̺�Ʈ(������ ��ġ, Ű�Է�, ��Ŀ�� ��)


	onUpdateControl(parentTransform);
}

//###########################################################################

void Control::onDraw(Graphics& g, const Transform& parentTransform)
{
	// TODO: �⺻���� �׸���(������ ��)


	onDrawControl(g, parentTransform);
}


END_NAMESPACE_CA_UI

