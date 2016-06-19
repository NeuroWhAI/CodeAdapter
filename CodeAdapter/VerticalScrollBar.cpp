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
	const auto& position = getPosition();
	const auto& size = getSize();


	f32 barLength = size.height / getMaxValue() * m_barLengthScale;

	if (barLength < m_minBarLength)
		barLength = m_minBarLength;
	if (barLength > size.height - 1)
		barLength = size.height - 1;


	f32 valuePerPixel = getMaxValue() / (size.height - barLength);


	f32 barYPosition = getValue() / valuePerPixel;


	if (barControlMode)
	{
		// �� ��Ʈ�� ��尡 ���۵ɶ�
		if (m_cursorOffset < 0)
		{
			// ��ġ�� ��ǥ�� ���� �����°��� ���
			m_cursorOffset = localCursor.y - barYPosition;
		}

		f32 cursorValue = (localCursor.y - m_cursorOffset) * valuePerPixel;

		setValue(cursorValue);

		barYPosition = getValue() / valuePerPixel;
	}
	else
	{
		// �� ��Ʈ�� ��尡 �ƴϹǷ� �÷��׸� �缳��
		m_cursorOffset = -256.0f;
	}


	f32 barXPosition = size.width * (1.0f - m_barThicknessRate);

	return RectangleF{ position.x + barXPosition,
		position.y + barYPosition,
		size.width * m_barThicknessRate - barXPosition, barLength };
}

//###########################################################################

f32 VerticalScrollBar::getBarLength() const
{
	return m_barRect.height;
}


END_NAMESPACE_CA_UI

