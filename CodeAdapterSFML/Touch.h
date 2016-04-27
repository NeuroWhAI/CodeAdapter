#ifndef __CA_SFML__TOUCH_H__
#define __CA_SFML__TOUCH_H__


#include <chrono>

#include "CodeAdapter\Touch.h"




namespace sf
{
	class RenderWindow;
}


class Touch : public CodeAdapter::System::Touch
{
private:
	using system_clock = std::chrono::system_clock;

	USING_CA(i32);
	USING_CA(f32);

	USING_CA_UTILITY_T(SharedObject, T);

	USING_CA_DRAWING(Point);
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(Window);


public:
	explicit Touch(SharedObject<sf::RenderWindow>& sharedWin);
	virtual ~Touch();


protected:
	SharedObject<sf::RenderWindow>& m_sharedWin;


protected:
	bool m_oldState, m_currentState;

	system_clock::time_point m_touchDownTime;
	bool m_oldLongState, m_currentLongState;


public:
	virtual void update() override;


public:
	virtual bool isDown() const override;
	virtual bool isPressed() const override;
	virtual bool isUp() const override;

	virtual bool isLongDown() const override;
	virtual bool isLongPressed() const override;
	virtual bool isLongUp() const override;

	virtual Point getPosition(Window& win) const override;
	virtual PointF getPositionF(Window& win) const override;
	virtual void getPosition(i32* pX, i32* pY, Window& win) const override;
	virtual void getPosition(f32* pX, f32* pY, Window& win) const override;
};


#endif