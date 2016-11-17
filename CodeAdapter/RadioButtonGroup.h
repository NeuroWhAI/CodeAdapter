#ifndef __CA__RADIO_BUTTON_GROUP_H__
#define __CA__RADIO_BUTTON_GROUP_H__


#include <vector>
#include <memory>

#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_UI


class RadioButtonGroup
{
public:
	using Ptr = std::shared_ptr<RadioButtonGroup>;


public:
	RadioButtonGroup();


protected:
	std::vector<std::weak_ptr<RadioButton>> m_group;


public:
	bool add(std::weak_ptr<RadioButton> radioButton);
	bool remove(const RadioButton* radioButton);


public:
	void uncheckExcept(const RadioButton* it);
};


END_NAMESPACE_CA_UI


#endif