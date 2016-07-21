#include "RadioButtonGroup.h"

#include "RadioButton.h"




BEGIN_NAMESPACE_CA_UI


RadioButtonGroup::RadioButtonGroup()
{

}

//###########################################################################

bool RadioButtonGroup::add(std::weak_ptr<RadioButton> radioButton)
{
	auto box = radioButton.lock();
	if (box)
	{
		m_group.emplace_back(radioButton);

		if (box->isChecked())
		{
			uncheckExcept(box.get());
		}


		return true;
	}


	return false;
}


bool RadioButtonGroup::remove(const RadioButton* radioButton)
{
	const size_t count = m_group.size();
	for (size_t i = 0; i < count; ++i)
	{
		auto box = m_group[i].lock();
		if (box && box.get() == radioButton)
		{
			m_group.erase(m_group.begin() + i);
			

			return true;
		}
	}


	return false;
}

//###########################################################################

void RadioButtonGroup::uncheckExcept(const RadioButton* it)
{
	for (auto& boxPtr : m_group)
	{
		auto box = boxPtr.lock();
		if (box && box.get() != it)
		{
			box->check(false);
		}
	}
}


END_NAMESPACE_CA_UI

