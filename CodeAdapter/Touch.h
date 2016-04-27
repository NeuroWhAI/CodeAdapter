#ifndef __CA__TOUCH_H__
#define __CA__TOUCH_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Point.h"




BEGIN_NAMESPACE_CA_SYSTEM


class Touch
{
public:
	Touch();
	virtual ~Touch();


protected:
	static std::shared_ptr<Touch> s_touchListener;


private:
	class Cleaner
	{
	public:
		virtual ~Cleaner()
		{
			if (s_touchListener)
			{
				s_touchListener.reset();
			}
		}
	};
	static Cleaner s_cleaner;


public:
	static Touch* getInstance();


public:
	virtual void update() = 0;


public:
	virtual bool isDown() const = 0;
	virtual bool isPressed() const = 0;
	virtual bool isUp() const = 0;

	virtual bool isLongDown() const = 0;
	virtual bool isLongPressed() const = 0;
	virtual bool isLongUp() const = 0;

	virtual Drawing::Point getPosition(Drawing::Window& win) const = 0;
	virtual Drawing::PointF getPositionF(Drawing::Window& win) const = 0;
	virtual void getPosition(i32* pX, i32* pY, Drawing::Window& win) const = 0;
	virtual void getPosition(f32* pX, f32* pY, Drawing::Window& win) const = 0;
};


END_NAMESPACE_CA_SYSTEM


#endif