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
	caDraw::PanelPtr m_panel;
	caDraw::FontPtr m_font;
	caDraw::DrawableRectanglePtr m_rect1;
	caDraw::DrawableEllipsePtr m_ellipse1;
	caDraw::DrawableLinePtr m_line1;
	caUI::LabelPtr m_desc;
	caUI::ProgressBarPtr m_progress;
	caUI::ButtonPtr m_buttonNext;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDrawBack(caDraw::Graphics& g) override;
	virtual void onDrawFront(caDraw::Graphics& g) override;
};


#endif