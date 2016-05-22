#ifndef __CA__WINDOW_EVENT_H__
#define __CA__WINDOW_EVENT_H__


#include "BasicDeclaration.h"

#include "Keys.h"




BEGIN_NAMESPACE_CA_SYSTEM


class WindowEvent
{
public:
	WindowEvent();
	virtual ~WindowEvent();


public:
	enum class Types
	{
		Unknown = -1,
		Closed = 0,
		Resized,
		TextEntered,

		//-------------
		Count
	};


protected:
	struct SizeEvent
	{
		i32 width, height;
	};

	struct TextEvent
	{
		u32 unicode;
	};


protected:
	Types m_eventType;


public:
	Types getType() const;
	void setType(Types type);


public:
	union
	{
		SizeEvent size;
		TextEvent text;
	};
};


END_NAMESPACE_CA_SYSTEM


#endif