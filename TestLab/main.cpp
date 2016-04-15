#include <iostream>

#include <CodeAdapter\CodeAdapter.h>
#include <CodeAdapterSFML\SFMLFactory.h>




using namespace CodeAdapter;

using std::cout;
using std::endl;
using std::cin;


int main()
{
	Factory::initializeInstance<SFMLFactory>();


	auto window = Factory::getInstance()->createWindow();
	window->create(Drawing::Size(1024, 768),
		Utility::String("Hello, World!"));


	auto panel = std::make_shared<Drawing::Panel>();
	//panel->addDrawable();

	window->addPanel(panel);


	while (window->isRunning())
	{
		window->update();
		window->draw(Drawing::Color::Gray);
	}


	return 0;
}

