#ifndef __CA__RADIO_BUTTON_H__
#define __CA__RADIO_BUTTON_H__


#include <memory>

#include "BasicDeclaration.h"

#include "CheckBox.h"




BEGIN_NAMESPACE_CA_UI


class RadioButton : public CheckBox
{
public:
	RadioButton();
	virtual ~RadioButton();


protected:
	std::weak_ptr<RadioButtonGroup> m_group;


public:
	virtual void onCheckedChanged(const EventArgs& args) override;


public:
	void setGroup(std::weak_ptr<RadioButtonGroup> group);
	void resetGroup();
};


END_NAMESPACE_CA_UI


#endif