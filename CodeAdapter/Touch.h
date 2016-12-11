#ifndef __CA__TOUCH_H__
#define __CA__TOUCH_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Point.h"




BEGIN_NAMESPACE_CA_SYSTEM


class Touch
{
private:
	USING_CA_DRAWING(Point);
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(Window);


public:
	Touch();
	virtual ~Touch();


protected:
	static std::shared_ptr<Touch> s_instance;


private:
	class Cleaner
	{
	public:
		virtual ~Cleaner()
		{
			if (s_instance)
			{
				s_instance.reset();
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

	virtual Point getPosition(Window& win) const = 0;
	virtual PointF getPositionF(Window& win) const = 0;
	virtual void getPosition(i32* pX, i32* pY, Window& win) const = 0;
	virtual void getPosition(f32* pX, f32* pY, Window& win) const = 0;
};


END_NAMESPACE_CA_SYSTEM


#endif