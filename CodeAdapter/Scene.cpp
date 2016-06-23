#include "Scene.h"

#include "Panel.h"




BEGIN_NAMESPACE_CA_UTILITY


Scene::Scene()
	: m_nextScene(this)
{

}


Scene::~Scene()
{
	reserveNextScene(nullptr);
}

//###########################################################################

void Scene::initialize(Window& owner)
{
	// TODO: 


	onInitialize(owner);
}


void Scene::release()
{
	onRelease();


	// TODO: 
}


void Scene::update(Window& win)
{
	for (auto& panel : m_panelList)
	{
		panel->update(win);
	}


	onUpdate(win);
}


void Scene::draw(Graphics& g)
{
	onDrawBack(g);


	for (auto& panel : m_panelList)
	{
		panel->draw(g);
	}


	onDrawFront(g);
}

//###########################################################################

void Scene::reserveNextScene(std::nullptr_t)
{
	if (m_nextScene != nullptr)
	{
		if (m_nextScene != this)
		{
			delete m_nextScene;
		}

		m_nextScene = nullptr;
	}
}

//###########################################################################

Scene* Scene::getNextScene()
{
	return m_nextScene;
}


void Scene::clearNextScene()
{
	m_nextScene = nullptr;
}

//###########################################################################

bool Scene::addPanel(std::shared_ptr<Panel> panel)
{
	for (const auto& panelItem : m_panelList)
	{
		if (panelItem == panel)
		{
			return false;
		}
	}


	m_panelList.emplace_back(panel);


	return true;
}


bool Scene::removePanel(std::shared_ptr<const Panel> panel)
{
	usize index = 0;
	for (const auto& panelItem : m_panelList)
	{
		if (panelItem == panel)
		{
			m_panelList.erase(m_panelList.begin() + index);

			return true;
		}

		++index;
	}


	return false;
}


END_NAMESPACE_CA_UTILITY

