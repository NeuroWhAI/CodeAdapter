#include "VerticalScrollBar.h"




BEGIN_NAMESPACE_CA_UI


VerticalScrollBar::VerticalScrollBar()
	: m_cursorOffset(-256.0f)
{

}


VerticalScrollBar::~VerticalScrollBar()
{

}

//###########################################################################

VerticalScrollBar::RectangleF VerticalScrollBar::onUpdateScrollBar(
	const Transform& parentTransform,
	const PointF& localCursor,
	bool barControlMode)
{
	f32 barLength = m_size.height / getMaxValue() * m_barLengthScale;

	if (barLength < m_minBarLength)
		barLength = m_minBarLength;
	if (barLength > m_size.height - 1)
		barLength = m_size.height - 1;


	f32 valuePerPixel = getMaxValue() / (m_size.height - barLength);


	f32 barYPosition = getValue() / valuePerPixel;


	if (barControlMode)
	{
		// 바 컨트롤 모드가 시작될때
		if (m_cursorOffset < 0)
		{
			// 터치한 좌표를 통해 오프셋값을 계산
			m_cursorOffset = localCursor.y - barYPosition;
		}

		f32 cursorValue = (localCursor.y - m_cursorOffset) * valuePerPixel;

		setValue(cursorValue);

		barYPosition = getValue() / valuePerPixel;
	}
	else
	{
		// 바 컨트롤 모드가 아니므로 플래그를 재설정
		m_cursorOffset = -256.0f;
	}


	f32 barXPosition = m_size.width * (1.0f - m_barThicknessRate);

	return RectangleF{ m_position.x + barXPosition,
		m_position.y + barYPosition,
		m_size.width * m_barThicknessRate - barXPosition, barLength };
}

//###########################################################################

f32 VerticalScrollBar::getBarLength() const
{
	return m_barRect.height;
}


END_NAMESPACE_CA_UI

