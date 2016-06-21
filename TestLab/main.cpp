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
	

	/*auto textbox1 = canew<caUI::TextBox>();
	textbox1->setFont(font1);
	textbox1->setTextMargin({ 8, 0 });
	textbox1->setBackColor(caDraw::Color::Gray);
	textbox1->setPosition({ 64, 420 });
	textbox1->setSize({ 330, 100 });*/


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

