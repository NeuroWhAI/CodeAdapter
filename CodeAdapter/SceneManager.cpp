#include "SceneManager.h"

#include "Scene.h"




BEGIN_NAMESPACE_CA_UTILITY


SceneManager::SceneManager()
	: m_scene(nullptr)
{
	
}


SceneManager::~SceneManager()
{
	if (m_scene)
	{
		m_scene->release();
		m_scene = nullptr;
	}
}

//###########################################################################

void SceneManager::replaceScene(Window& owner, std::shared_ptr<Scene> nextScene)
{
	if (m_scene)
	{
		m_scene->release();
		m_scene->clearNextScene();
	}

	m_scene = nextScene;

	if (nextScene)
	{
		nextScene->initialize(owner);
	}
}


void SceneManager::update(Window& owner)
{
	if (m_scene)
	{
		m_scene->update(owner);


		auto nextScene = m_scene->getNextScene();

		if (nextScene != m_scene.get())
		{
			replaceScene(owner, std::shared_ptr<Scene>(nextScene));
		}
	}
}


void SceneManager::draw(Graphics& g)
{
	if (m_scene)
	{
		m_scene->draw(g);
	}
}


bool SceneManager::hasScene() const
{
	return (m_scene != nullptr);
}


END_NAMESPACE_CA_UTILITY

