#include "TextBox.h"

#include "Keyboard.h"

#include "Transform.h"
#include "Graphics.h"

#include "TextArtist.h"
#include "Rectangle.h"




BEGIN_NAMESPACE_CA_UI


TextBox::TextBox()
	: Control(true)

	, m_textMargin(0, 0)

	, m_cursorIndex(0)
{

}


TextBox::~TextBox()
{

}

//###########################################################################

void TextBox::onKeyDown(const KeyEventArgs& args)
{
	using Keys = System::Keys;


	auto& text = getMyText();


	switch (args.key)
	{
	case Keys::Left:
		if (m_cursorIndex > 0)
		{
			--m_cursorIndex;
		}
		break;

	case Keys::Right:
		if (m_cursorIndex < text.getLength())
		{
			++m_cursorIndex;
		}
		break;

	case Keys::Home:
		m_cursorIndex = 0;
		break;

	case Keys::End:
		m_cursorIndex = text.getLength();
		break;

	case Keys::Delete:
		if (m_cursorIndex < text.getLength())
		{
			text.eraseAt(m_cursorIndex);


			EventArgs args;
			onTextChanged(args);
		}
		break;
	}
}

//--------------------------------------------------------------------------

void TextBox::onSelected(const EventArgs& args)
{

}


void TextBox::onDeselected(const EventArgs& args)
{

}

//###########################################################################

void TextBox::onUpdateControl(const Transform& parentTransform, const PointF& localCursor)
{
	if (isSelected())
	{
		auto keyboard = System::Keyboard::getInstance();


		auto& text = getMyText();


		u32 unicode = 0;
		if (keyboard->getTypedText(&unicode))
		{
			const wchar_t ch = static_cast<wchar_t>(unicode);
			
			
			if (ch == L'\b'/*Key_Backspace*/)
			{
				if (m_cursorIndex > 0
					&& m_cursorIndex <= text.getLength())
				{
					--m_cursorIndex;
					text.eraseAt(m_cursorIndex);


					EventArgs args;
					onTextChanged(args);
				}
			}
			else if (ch == 0x1b/*Key_Escape*/)
			{
				setSelect(false);
			}
			else if (ch != 0x0d/*Key_Return*/)
			{
				text.InsertChar(ch, m_cursorIndex);
				++m_cursorIndex;


				EventArgs args;
				onTextChanged(args);
			}
		}
	}
}


void TextBox::onDrawControl(Graphics& g, const Transform& parentTransform)
{
	if (!m_font.expired())
	{
		const auto& position = getPosition();
		const auto& size = getSize();

		const auto& text = getText();


		auto& artist = g.textArtist;


		artist->initialize(parentTransform);


		artist->beginDrawString(*m_font.lock());

		artist->drawString(text,
			position.x + m_textMargin.x,
			position.y + size.height / 2 + m_textMargin.y,
			m_foreColor,
			Drawing::TextAligns::Right);

		// 선택된 상태이면
		if (isSelected())
		{
			// 커서를 그림

			Utility::String beforeCursorText = text;

			if (m_cursorIndex < beforeCursorText.getLength())
			{
				beforeCursorText.eraseToEnd(m_cursorIndex);
			}

			auto beforeCursorRect = artist->getBoundRectangle(beforeCursorText);

			artist->drawString(L"｜",
				position.x + beforeCursorRect.x + beforeCursorRect.width + m_textMargin.x,
				position.y + size.height / 2 + m_textMargin.y,
				m_foreColor,
				Drawing::TextAligns::Right);
		}

		artist->endDrawString();
	}
}

//###########################################################################

void TextBox::setTextMargin(const PointF& margin)
{
	m_textMargin = margin;
}


const TextBox::PointF& TextBox::getTextMargin() const
{
	return m_textMargin;
}


END_NAMESPACE_CA_UI

