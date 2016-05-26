#include "TextBox.h"

#include "Keyboard.h"

#include "Transform.h"
#include "Graphics.h"

#include "TextArtist.h"
#include "Rectangle.h"




BEGIN_NAMESPACE_CA_UI


TextBox::TextBox()
	: Control(true)

	, m_text("")
	, m_textColor(Color::Black)
	, m_textMargin(0, 0)

	, m_cursorIndex(0)
{

}


TextBox::~TextBox()
{

}

//###########################################################################

void TextBox::onTextChanged(const EventArgs& args)
{
	if (WhenTextChanged)
	{
		WhenTextChanged(args);
	}
}

//###########################################################################

void TextBox::onKeyDown(const KeyEventArgs& args)
{
	using Keys = System::Keys;

	switch (args.key)
	{
	case Keys::Left:
		if (m_cursorIndex > 0)
		{
			--m_cursorIndex;
		}
		break;

	case Keys::Right:
		if (m_cursorIndex < m_text.getLength())
		{
			++m_cursorIndex;
		}
		break;

	case Keys::Home:
		m_cursorIndex = 0;
		break;

	case Keys::End:
		m_cursorIndex = m_text.getLength();
		break;

	case Keys::Delete:
		if (m_cursorIndex < m_text.getLength())
		{
			m_text.eraseAt(m_cursorIndex);


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

		u32 unicode = 0;
		if (keyboard->getTypedText(&unicode))
		{
			const wchar_t ch = static_cast<wchar_t>(unicode);
			
			
			if (ch == L'\b'/*Key_Backspace*/)
			{
				if (m_cursorIndex > 0
					&& m_cursorIndex <= m_text.getLength())
				{
					--m_cursorIndex;
					m_text.eraseAt(m_cursorIndex);


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
				m_text.InsertChar(ch, m_cursorIndex);
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
		auto& artist = g.textArtist;


		artist->initialize(parentTransform);


		artist->beginDrawString(*m_font.lock());

		artist->drawString(m_text,
			m_position.x + m_textMargin.x,
			m_position.y + m_textMargin.y,
			m_textColor,
			Drawing::TextAligns::RightBottom);

		// 선택된 상태이면
		if (isSelected())
		{
			// 커서를 그림

			Utility::String beforeCursorText = m_text;

			if (m_cursorIndex < beforeCursorText.getLength())
			{
				beforeCursorText.eraseToEnd(m_cursorIndex);
			}

			auto beforeCursorRect = artist->getBoundRectangle(beforeCursorText);

			artist->drawString(L"｜",
				m_position.x + beforeCursorRect.x + beforeCursorRect.width + m_textMargin.x,
				m_position.y + m_textMargin.y,
				m_textColor,
				Drawing::TextAligns::RightBottom);
		}

		artist->endDrawString();
	}
}

//###########################################################################

void TextBox::setText(const Utility::String& text)
{
	if (m_text != text)
	{
		m_text = text;


		EventArgs args;
		onTextChanged(args);
	}
}


const Utility::String& TextBox::getText() const
{
	return m_text;
}


void TextBox::setFont(std::weak_ptr<Drawing::Font> font)
{
	m_font = font;
}


void TextBox::setTextColor(const Color& textColor)
{
	m_textColor = textColor;
}


const TextBox::Color& TextBox::getTextColor() const
{
	return m_textColor;
}


void TextBox::setTextMargin(const PointF& margin)
{
	m_textMargin = margin;
}


const TextBox::PointF& TextBox::getTextMargin() const
{
	return m_textMargin;
}


END_NAMESPACE_CA_UI

