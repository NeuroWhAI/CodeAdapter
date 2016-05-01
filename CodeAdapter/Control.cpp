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
	// TODO: 기본적인 이벤트(영역내 터치, 키입력, 포커스 등)


	onUpdateControl(parentTransform);
}

//###########################################################################

void Control::onDraw(Graphics& g, const Transform& parentTransform)
{
	// TODO: 기본적인 그리기(색상배경 등)


	onDrawControl(g, parentTransform);
}


END_NAMESPACE_CA_UI

