#include "TextBox.h"

#include "Keyboard.h"

#include "Transform.h"
#include "Graphics.h"
#include "Font.h"

#include "TextArtist.h"
#include "RectangleArtist.h"
#include "Rectangle.h"




BEGIN_NAMESPACE_CA_UI


TextBox::TextBox()
	: Control(true)

	, m_textMargin(0, 0)
	, m_isMultiline(false)

	, m_cursorIndex(0, 0)
	, m_lineSpacing(1)
{
	m_focusOverlayColor = Color(Color::White, 64);
	m_touchOverlayColor = m_focusOverlayColor;


	m_linedText.emplace_back();
}


TextBox::~TextBox()
{

}

//###########################################################################

void TextBox::onKeyDown(const KeyEventArgs& args)
{
	using Keys = System::Keys;


	switch (args.key)
	{
	case Keys::Left:
		--m_cursorIndex.x;
		if (m_cursorIndex.x < 0)
		{
			if (m_cursorIndex.y > 0)
			{
				--m_cursorIndex.y;
				m_cursorIndex.x = m_linedText[m_cursorIndex.y].getLength();
			}
			else
			{
				m_cursorIndex.x = 0;
			}
		}
		break;

	case Keys::Right:
		++m_cursorIndex.x;
		if (m_cursorIndex.x > m_linedText[m_cursorIndex.y].getLength())
		{
			if (m_cursorIndex.y + 1 < static_cast<i32>(m_linedText.size()))
			{
				++m_cursorIndex.y;
				m_cursorIndex.x = 0;
			}
			else
			{
				--m_cursorIndex.x;
			}
		}
		break;

	case Keys::Up:
		if (m_cursorIndex.y > 0)
		{
			--m_cursorIndex.y;

			i32 lineLength = m_linedText[m_cursorIndex.y].getLength();
			if (m_cursorIndex.x > lineLength)
			{
				m_cursorIndex.x = lineLength;
			}
		}
		break;

	case Keys::Down:
		if (m_cursorIndex.y + 1 < static_cast<i32>(m_linedText.size()))
		{
			++m_cursorIndex.y;

			i32 lineLength = m_linedText[m_cursorIndex.y].getLength();
			if (m_cursorIndex.x > lineLength)
			{
				m_cursorIndex.x = lineLength;
			}
		}
		break;

	case Keys::Home:
		m_cursorIndex.x = 0;
		break;

	case Keys::End:
		m_cursorIndex.x = m_linedText[m_cursorIndex.y].getLength();
		break;

	case Keys::Delete:
		if (m_cursorIndex.x < m_linedText[m_cursorIndex.y].getLength())
		{
			m_linedText[m_cursorIndex.y].eraseAt(m_cursorIndex.x);
			

			syncMyText();
		}
		else if(m_cursorIndex.y + 1 < static_cast<i32>(m_linedText.size()))
		{
			m_linedText[m_cursorIndex.y] += m_linedText[m_cursorIndex.y + 1];
			m_linedText.erase(m_linedText.begin() + (m_cursorIndex.y + 1));
			

			syncMyText();
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
				if (m_cursorIndex.x > 0)
				{
					if (m_cursorIndex.x <= m_linedText[m_cursorIndex.y].getLength())
					{
						--m_cursorIndex.x;
						m_linedText[m_cursorIndex.y].eraseAt(m_cursorIndex.x);
						

						syncMyText();
					}
				}
				else if(m_cursorIndex.y > 0)
				{
					m_cursorIndex.x = m_linedText[m_cursorIndex.y - 1].getLength();

					m_linedText[m_cursorIndex.y - 1] += m_linedText[m_cursorIndex.y];
					m_linedText.erase(m_linedText.begin() + m_cursorIndex.y);

					--m_cursorIndex.y;


					syncMyText();
				}
			}
			else if (ch == 0x1b/*Key_Escape*/)
			{
				setSelect(false);
			}
			else if (ch == 0x0d/*Key_Return*/)
			{
				if (m_isMultiline)
				{
					auto temp = m_linedText[m_cursorIndex.y];
					temp.eraseRange(0, m_cursorIndex.x);

					m_linedText[m_cursorIndex.y].eraseToEnd(m_cursorIndex.x);
					m_linedText.insert(m_linedText.begin() + (m_cursorIndex.y + 1), temp);

					++m_cursorIndex.y;
					m_cursorIndex.x = 0;


					syncMyText();
				}
			}
			else
			{
				m_linedText[m_cursorIndex.y].InsertChar(ch, m_cursorIndex.x);
				++m_cursorIndex.x;


				syncMyText();
			}
		}
	}
}


void TextBox::onDrawControl(Graphics& g, const Transform& parentTransform)
{
	auto& rectArtist = g.rectangleArtist;


	rectArtist->beginFillRectangle();
	rectArtist->fillRectangle(getPosition(), getSize(), getOverlayColor());
	rectArtist->endFillRectangle();


	auto font = m_font.lock();
	if (font)
	{
		const auto& position = getPosition();
		const auto& size = getSize();

		const auto& text = getText();


		auto& textArtist = g.textArtist;


		textArtist->initialize(parentTransform);


		textArtist->beginDrawString(*font);

		const f32 alignY = m_lineSpacing / 2 * (m_linedText.size() - 1);

		f32 lineY = 0;
		for (const auto& str : m_linedText)
		{
			textArtist->drawString(str,
				position.x + m_textMargin.x,
				position.y - alignY + lineY + size.height / 2 + m_textMargin.y,
				m_foreColor,
				Drawing::TextAligns::Right);

			lineY += m_lineSpacing;
		}

		// 선택된 상태이면
		if (isSelected())
		{
			// 커서를 그림

			Utility::String beforeCursorText = m_linedText[m_cursorIndex.y];

			if (m_cursorIndex.x < beforeCursorText.getLength())
			{
				beforeCursorText.eraseToEnd(m_cursorIndex.x);
			}

			auto beforeCursorRect = textArtist->getBoundRectangle(beforeCursorText);

			textArtist->drawString(L"｜",
				position.x + beforeCursorRect.x + beforeCursorRect.width + m_textMargin.x,
				position.y - alignY + m_cursorIndex.y * m_lineSpacing + size.height / 2 + m_textMargin.y,
				m_foreColor,
				Drawing::TextAligns::Right);
		}

		textArtist->endDrawString();
	}
}

//###########################################################################

void TextBox::setText(const String& text)
{
	Control::setText(text);


	m_linedText.clear();

	const auto str = static_cast<std::wstring>(text);

	String buffer;

	for (const auto ch : str)
	{
		if (ch == L'\n' || ch == L'\0')
		{
			m_linedText.emplace_back(buffer);

			buffer.setStr(L"");
		}
		else
		{
			buffer.addChar(ch);
		}
	}

	if (buffer.getLength() > 0)
	{
		m_linedText.emplace_back(buffer);
	}
	else if (m_linedText.size() <= 0)
	{
		m_linedText.emplace_back();
	}


	// 커서를 맨 끝으로 이동시킴.
	m_cursorIndex = { 0, 0 };

	if (m_linedText.size() > 0)
	{
		m_cursorIndex.y = static_cast<i32>(m_linedText.size() - 1);
		m_cursorIndex.x = m_linedText[m_cursorIndex.y].getLength();
	}
}


void TextBox::setFont(std::weak_ptr<Font> font)
{
	Control::setFont(font);


	auto lockFont = font.lock();
	if (lockFont)
	{
		m_lineSpacing = static_cast<f32>(lockFont->getCharacterSize());
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


void TextBox::setMultiline(bool isMultiline)
{
	m_isMultiline = isMultiline;
}


bool TextBox::isMultiline() const noexcept
{
	return m_isMultiline;
}

//###########################################################################

void TextBox::syncMyText()
{
	auto& text = getMyText();

	text = m_linedText[0];

	for (size_t i = 1; i < m_linedText.size(); ++i)
	{
		text.addChar(L'\n');
		text += m_linedText[i];
	}


	EventArgs args;
	onTextChanged(args);
}


END_NAMESPACE_CA_UI

