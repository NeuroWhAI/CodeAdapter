#include "ListBox.h"

#include <algorithm>

#include "Transform.h"
#include "Graphics.h"

#include "VerticalScrollBar.h"

#include "Font.h"
#include "TextArtist.h"
#include "RectangleArtist.h"




BEGIN_NAMESPACE_CA_UI


ListBox::ListBox()
	: Control(false)

	, m_itemMargin(0, 0)

	, m_selectedIndex(-1)

	, m_verticalBar(std::make_unique<VerticalScrollBar>())
{
	m_verticalBar->setSize({ 24.0f, getSize().height });
}


ListBox::ListBox(const ListBox& right)
	: Control(right)

	, m_itemMargin(right.m_itemMargin)

	, m_item(right.m_item)

	, m_selectedIndex(right.m_selectedIndex)

	, m_verticalBar(std::make_unique<VerticalScrollBar>(*right.m_verticalBar))

	, WhenSelectedIndexChanged(right.WhenSelectedIndexChanged)
{

}


ListBox::~ListBox()
{

}

//###########################################################################

void ListBox::onSelectedIndexChanged(const ValueEventArgs& args)
{
	if (WhenSelectedIndexChanged)
	{
		WhenSelectedIndexChanged(args);
	}
}

//###########################################################################

void ListBox::onMove(const EventArgs& args)
{
	Control::onMove(args);


	updateScrollBar();
}

//--------------------------------------------------------------------------

void ListBox::onResize(const EventArgs& args)
{
	Control::onResize(args);


	updateScrollBar();
}

//--------------------------------------------------------------------------

void ListBox::onTouchDown(const TouchEventArgs& args)
{
	Control::onTouchDown(args);


	if (args.x - getPosition().x < getSize().width - m_verticalBar->getSize().width)
	{
		auto font = m_font.lock();
		if (font)
		{
			const auto& position = getPosition();

			const auto fontHeight = font->getCharacterSize();
			const auto itemHeight = fontHeight + m_itemMargin.y;

			auto barValue = m_verticalBar->getValue();
			f32 index = (args.y - position.y - fontHeight + barValue) / itemHeight;
			if (index < 0
				|| (index >= 0 && static_cast<size_t>(index) >= m_item.size()))
			{
				index = -1;
			}

			selectItemAt(static_cast<i32>(index));
		}
		else
		{
			deselectItem();
		}
	}
}

//###########################################################################

void ListBox::onUpdateControl(const Transform& parentTransform, const PointF& parentCursor,
	const Transform& localTransform, const PointF& localCursor)
{
	m_verticalBar->update(parentTransform, static_cast<Point>(parentCursor));
}


void ListBox::onDrawControl(Graphics& g, const Transform& parentTransform)
{
	auto font = m_font.lock();
	if (font)
	{
		const auto& position = getPosition();
		const auto& size = getSize();


		auto& textArtist = g.textArtist;
		auto& rectArtist = g.rectangleArtist;


		auto barValue = m_verticalBar->getValue();


		const auto fontHeight = font->getCharacterSize();
		const auto jumpHeight = fontHeight + m_itemMargin.y;


		if (hasSelectedItem())
		{
			rectArtist->beginFillRectangle();

			rectArtist->fillRectangle(position.x,
				position.y + jumpHeight * m_selectedIndex + fontHeight - barValue,
				size.width, jumpHeight,
				m_touchOverlayColor);

			rectArtist->endFillRectangle();
		}


		f32 yPos = static_cast<f32>(fontHeight / 2) - barValue;

		textArtist->beginDrawString(*font);

		for (const auto& item : m_item)
		{
			textArtist->drawString(item,
				position.x + m_itemMargin.x,
				position.y + m_itemMargin.y + yPos,
				m_foreColor,
				Drawing::TextAligns::Right);

			yPos += jumpHeight;
		}

		textArtist->endDrawString();
	}


	m_verticalBar->draw(g, parentTransform);
}

//###########################################################################

ListBox& ListBox::operator= (const ListBox& right)
{
	if (this != &right)
	{
		Control::operator=(right);


		m_itemMargin = right.m_itemMargin;
		

		m_item = right.m_item;


		m_selectedIndex = right.m_selectedIndex;


		m_verticalBar->operator=(*right.m_verticalBar);


		WhenSelectedIndexChanged = right.WhenSelectedIndexChanged;
	}


	return *this;
}

//###########################################################################

void ListBox::setItemMargin(const PointF& margin)
{
	m_itemMargin = margin;
}


auto ListBox::getItemMargin() const -> const PointF&
{
	return m_itemMargin;
}

//###########################################################################

void ListBox::addItem(const String& text)
{
	m_item.emplace_back(text);


	updateScrollBar();
}


void ListBox::insertItem(i32 index, const String& text)
{
	m_item.insert(m_item.begin() + index, text);


	if (hasSelectedItem()
		&& index <= m_selectedIndex)
	{
		// NOTE: 단순히 밀려나는 것이므로 이벤트 발생 없음.
		++m_selectedIndex;
	}


	updateScrollBar();
}


void ListBox::removeItem(const String& text)
{
	auto it = std::find(m_item.begin(), m_item.end(), text);

	if (it != m_item.end())
	{
		removeItemAt(it - m_item.begin());
	}
}


void ListBox::removeItemAt(i32 index)
{
	m_item.erase(m_item.begin() + index);


	if (index < m_selectedIndex)
	{
		// NOTE: 단순히 당겨지는 것이므로 이벤트 발생 없음.
		--m_selectedIndex;
	}
	else if (index == m_selectedIndex)
	{
		deselectItem();
	}


	updateScrollBar();
}


i32 ListBox::itemIndexOf(const String& text) const
{
	i32 index = 0;
	for (auto& item : m_item)
	{
		if (item == text)
		{
			return index;
		}

		++index;
	}


	return -1;
}


void ListBox::clearItems()
{
	m_item.clear();


	deselectItem();


	updateScrollBar();
}


auto ListBox::getItemCount() const -> i32
{
	return static_cast<i32>(m_item.size());
}


auto ListBox::getItemHeight() const -> i32
{
	auto font = m_font.lock();
	if (font)
	{
		return static_cast<i32>(font->getCharacterSize() + m_itemMargin.y);
	}


	return 0;
}

//###########################################################################

bool ListBox::hasSelectedItem() const
{
	return (m_selectedIndex >= 0);
}


i32 ListBox::getSelectedIndex() const
{
	return m_selectedIndex;
}


void ListBox::selectItemAt(i32 index)
{
	if (index < 0)
		index = -1;
	else if (static_cast<size_t>(index) >= m_item.size())
		throw std::invalid_argument("Out of range.");


	if (m_selectedIndex != index)
	{
		m_selectedIndex = index;


		ValueEventArgs args(index);
		onSelectedIndexChanged(args);
	}
}


void ListBox::deselectItem()
{
	selectItemAt(-1);
}

//###########################################################################

void ListBox::updateScrollBar()
{
	const auto& position = getPosition();
	const auto& size = getSize();


	// 스크롤바 위치, 크기 갱신
	m_verticalBar->setPosition({ position.x + size.width - 24, position.y });
	m_verticalBar->setSize({ 24, size.height });
	m_verticalBar->setMinBarLength(std::min(36.0f, size.height));


	auto itemHeight = getItemHeight();
	if (itemHeight > 0)
	{
		f32 height = static_cast<f32>(itemHeight * m_item.size());

		m_verticalBar->setMaxValue(std::max(0.0f,
			height - getSize().height + itemHeight));
	}
}


END_NAMESPACE_CA_UI

