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
	f32 barLength = m_size.width / getMaxValue() * m_barLengthScale;

	if (barLength < m_minBarLength)
		barLength = m_minBarLength;
	if (barLength > m_size.width - 1)
		barLength = m_size.width - 1;


	f32 valuePerPixel = getMaxValue() / (m_size.width - barLength);


	f32 barXPosition = getValue() / valuePerPixel;


	if (barControlMode)
	{
		// �� ��Ʈ�� ��尡 ���۵ɶ�
		if (m_cursorOffset < 0)
		{
			// ��ġ�� ��ǥ�� ���� �����°��� ���
			m_cursorOffset = localCursor.x - barXPosition;
		}

		f32 cursorValue = (localCursor.x - m_cursorOffset) * valuePerPixel;

		setValue(cursorValue);

		barXPosition = getValue() / valuePerPixel;
	}
	else
	{
		// �� ��Ʈ�� ��尡 �ƴϹǷ� �÷��׸� �缳��
		m_cursorOffset = -256.0f;
	}


	f32 barYPosition = m_size.height * (1.0f - m_barThicknessRate);

	return RectangleF{ m_position.x + barXPosition,
		m_position.y + barYPosition,
		barLength, m_size.height * m_barThicknessRate - barYPosition };
}

//###########################################################################

f32 HorizontalScrollBar::getBarLength() const
{
	return m_barRect.width;
}


END_NAMESPACE_CA_UI

