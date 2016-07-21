#include "RadioButton.h"

#include "RadioButtonGroup.h"




BEGIN_NAMESPACE_CA_UI


RadioButton::RadioButton()
{

}


RadioButton::~RadioButton()
{

}

//###########################################################################

void RadioButton::onCheckedChanged(const EventArgs& args)
{
	if (isChecked())
	{
		auto group = m_group.lock();
		if (group)
		{
			group->uncheckExcept(this);
		}
	}


	CheckBox::onCheckedChanged(args);
}

//###########################################################################

void RadioButton::setGroup(std::weak_ptr<RadioButtonGroup> group)
{
	m_group = group;
}


void RadioButton::resetGroup()
{
	m_group.reset();
}


END_NAMESPACE_CA_UI

