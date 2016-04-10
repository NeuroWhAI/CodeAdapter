#include <iostream>

#include <CodeAdapter\CodeAdapter.h>
#include <CodeAdapterSFML\Factory.h>




using std::cout;
using std::endl;
using std::cin;


int main()
{
	CodeAdapter::Factory::initializeInstance<Factory>();


	auto window = CodeAdapter::Factory::getInstance()->createWindow();
	window->create(CodeAdapter::Drawing::Size(1024, 768),
		CodeAdapter::Utility::String("Hello, World!"));

	while (window->isRunning())
	{
		window->update();
		window->draw(CodeAdapter::Drawing::Color::Gray);
	}


	return 0;
}

