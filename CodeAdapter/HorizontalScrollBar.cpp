#include "HorizontalScrollBar.h"




BEGIN_NAMESPACE_CA_UI


HorizontalScrollBar::HorizontalScrollBar()
	: m_cursorOffset(-256.0f)
{

}


HorizontalScrollBar::~HorizontalScrollBar()
{

}

//###########################################################################

HorizontalScrollBar::RectangleF HorizontalScrollBar::onUpdateScrollBar(
	const Transform& parentTransform,
	const PointF& localCursor,
	bool barControlMode)
{
	const auto& position = getPosition();
	const auto& size = getSize();


	f32 barLength = size.width / getMaxValue() * m_barLengthScale;

	if (barLength < m_minBarLength)
		barLength = m_minBarLength;
	if (barLength > size.width - 1)
		barLength = size.width - 1;


	f32 valuePerPixel = getMaxValue() / (size.width - barLength);


	f32 barXPosition = getValue() / valuePerPixel;


	if (barControlMode)
	{
		// 바 컨트롤 모드가 시작될때
		if (m_cursorOffset < 0)
		{
			// 터치한 좌표를 통해 오프셋값을 계산
			m_cursorOffset = localCursor.x - barXPosition;
		}

		f32 cursorValue = (localCursor.x - m_cursorOffset) * valuePerPixel;

		setValue(cursorValue);

		barXPosition = getValue() / valuePerPixel;
	}
	else
	{
		// 바 컨트롤 모드가 아니므로 플래그를 재설정
		m_cursorOffset = -256.0f;
	}


	f32 barYPosition = size.height * (1.0f - m_barThicknessRate);

	return RectangleF{ position.x + barXPosition,
		position.y + barYPosition,
		barLength, size.height * m_barThicknessRate - barYPosition };
}

//###########################################################################

f32 HorizontalScrollBar::getBarLength() const
{
	return m_barRect.width;
}


END_NAMESPACE_CA_UI

