#ifndef __DEMO1_SCENE_H__
#define __DEMO1_SCENE_H__


#include "CodeAdapter\EasyCA.h"




class Demo1Scene : public caUtil::Scene
{
public:
	explicit Demo1Scene(const caUtil::ResourcePool& pool);
	virtual ~Demo1Scene();


protected:
	caUtil::ResourcePool m_pool;


protected:
	std::shared_ptr<caDraw::Panel> m_panel;
	std::shared_ptr<caDraw::Font> m_font;
	std::shared_ptr<caDraw::DrawableRectangle> m_rect1;
	std::shared_ptr<caDraw::DrawableEllipse> m_ellipse1;
	std::shared_ptr<caDraw::DrawableLine> m_line1;
	std::shared_ptr<caUI::Label> m_desc;
	std::shared_ptr<caUI::Button> m_buttonNext;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDrawBack(caDraw::Graphics& g) override;
	virtual void onDrawFront(caDraw::Graphics& g) override;
};


#endif