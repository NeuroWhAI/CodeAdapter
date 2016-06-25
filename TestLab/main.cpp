#include <CodeAdapter\EasyCA.h>
#include <CodeAdapterSFML\SFMLFactory.h>

#include "HelloScene.h"




int main()
{
	initializeCA<SFMLFactory>();


	auto window1 = caFactory->createWindow();
	window1->create(caDraw::Size(1024, 768), caUtil::String("Hello, World!"));


	auto sceneManager = canew<caUtil::SceneManager>();
	sceneManager->replaceScene(*window1, canew<HelloScene>());

	window1->setSceneManager(sceneManager);


	while (window1->isRunning())
	{
		caTouch->update();
		caKeyboard->update(*window1);


		if (sceneManager->hasScene() == false)
			window1->exit();


		window1->update();
		window1->draw(caDraw::Color(230, 230, 230));
	}


	return 0;
}

