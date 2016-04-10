#ifndef __CA__PANEL_H__
#define __CA__PANEL_H__


#include "Definition.h"
#include "CAType.h"




BEGIN_NAMESPACE_CA_DRAWING


class Panel
{
public:
	Panel();
	virtual ~Panel();


public:
	void update();
	void draw();
};


END_NAMESPACE_CA_DRAWING


#endif