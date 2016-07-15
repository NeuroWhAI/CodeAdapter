#include "TextBox.h"

#include <algorithm>

#include "Keyboard.h"

#include "Transform.h"
#include "Graphics.h"
#include "Font.h"

#include "TextArtist.h"
#include "RectangleArtist.h"
#include "Rectangle.h"
#include "VerticalScrollBar.h"




BEGIN_NAMESPACE_CA_UI


TextBox::TextBox()
	: Control(true)

	, m_textMargin(0, 0)
	, m_isMultiline(false)

	, m_cursorIndex(0, 0)
	, m_lineSpacing(1)

	, m_verticalBar(std::make_unique<VerticalScrollBar>())
{
	m_focusOverlayColor = Color(Color::White, 64);
	m_touchOverlayColor = m_focusOverlayColor;


	m_linedText.emplace_back();


	m_verticalBar->setSize({ 24.0f, getSize().height });
}


TextBox::TextBox(const TextBox& right)
	: Control(right)

	, m_textMargin(right.m_textMargin)
	, m_isMultiline(right.m_isMultiline)

	, m_cursorIndex(right.m_cursorIndex)
	, m_linedText(right.m_linedText)
	, m_lineSpacing(right.m_lineSpacing)

	, m_verticalBar(std::make_unique<VerticalScrollBar>(*right.m_verticalBar))
{

}


TextBox::~TextBox()
{

}

//###########################################################################

void TextBox::onResize(const EventArgs& args)
{
	Control::onResize(args);


	const auto& size = getSize();


	// 스크롤바 위치, 길이 재설정
	m_verticalBar->setPosition({ size.width - 24, 0 });
	m_verticalBar->setSize({ 24, size.height });
	m_verticalBar->setMinBarLength(std::min(36.0f, size.height));
}

//--------------------------------------------------------------------------

void TextBox::onKeyDown(const KeyEventArgs& args)
{
	Control::onKeyDown(args);


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

//###########################################################################

void TextBox::onUpdateControl(const Transform& parentTransform, const PointF& parentCursor,
	const Transform& localTransform, const PointF& localCursor)
{
	// 스크롤바 갱신
	if (m_isMultiline)
	{
		updateScrollBar();

		m_verticalBar->update(parentTransform, static_cast<Point>(parentCursor));
	}


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


		const f32 verticalScroll = m_verticalBar->getValue() * m_lineSpacing;


		auto& textArtist = g.textArtist;


		textArtist->beginDrawString(*font);

		f32 lineY = m_lineSpacing / 2 + m_textMargin.y - verticalScroll;
		for (const auto& str : m_linedText)
		{
			textArtist->drawString(str,
				position.x + m_textMargin.x,
				position.y + lineY,
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

			lineY = m_lineSpacing / 2 - verticalScroll;

			textArtist->drawString(L"｜",
				position.x + beforeCursorRect.x + beforeCursorRect.width + m_textMargin.x,
				position.y + lineY + m_cursorIndex.y * m_lineSpacing + m_textMargin.y,
				m_foreColor,
				Drawing::TextAligns::Right);
		}

		textArtist->endDrawString();
	}

	
	// 스크롤바
	if (m_isMultiline)
	{
		m_verticalBar->draw(g, parentTransform);
	}
}

//###########################################################################

TextBox& TextBox::operator= (const TextBox& right)
{
	Control::operator=(right);


	m_textMargin = right.m_textMargin;
	m_isMultiline = right.m_isMultiline;


	m_cursorIndex = right.m_cursorIndex;
	m_linedText = right.m_linedText;
	m_lineSpacing = right.m_lineSpacing;


	m_verticalBar->operator=(*right.m_verticalBar);


	return *this;
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


	// 스크롤바 갱신
	if (m_isMultiline)
	{
		updateScrollBar();
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


void TextBox::updateScrollBar()
{
	f32 height = m_lineSpacing * static_cast<f32>(m_linedText.size());
	height += m_textMargin.y * 2;

	m_verticalBar->setMaxValue(std::max(0.0f,
		(height - getSize().height) / m_lineSpacing));
}


END_NAMESPACE_CA_UI

