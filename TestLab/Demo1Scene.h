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
	caDraw::Panel::Ptr m_panel;
	caDraw::Font::Ptr m_font;
	caDraw::DrawableRectangle::Ptr m_rect1;
	caDraw::DrawableEllipse::Ptr m_ellipse1;
	caDraw::DrawableLine::Ptr m_line1;
	caUI::Label::Ptr m_desc;
	caUI::ProgressBar::Ptr m_progress;
	caUI::Button::Ptr m_buttonNext;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDrawBack(caDraw::Graphics& g) override;
	virtual void onDrawFront(caDraw::Graphics& g) override;
};


#endif