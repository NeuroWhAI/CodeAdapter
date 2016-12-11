#include "Panel.h"




BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
bool Panel::addItemTo(std::vector<std::weak_ptr<T>>& list, std::weak_ptr<T> item)
{
	// 중복 확인
	auto target = item.lock();

	for (const auto& item : list)
	{
		if (target == item.lock())
		{
			// 중복
			return false;
		}
	}

	// 중복 아님


	list.emplace_back(item);


	return true;
}


template <typename T>
bool Panel::removeItemFrom(std::vector<std::weak_ptr<T>>& list, std::weak_ptr<const T> item)
{
	// 존재 확인
	auto target = item.lock();

	usize index = 0;
	for (const auto& item : list)
	{
		// 존재
		if (target == item.lock())
		{
			// 삭제
			list.erase(list.begin() + index);

			return true;
		}

		++index;
	}

	// 존재 안함


	return false;
}


END_NAMESPACE_CA_DRAWING

