#include <CodeAdapter\CodeAdapter.h>
#include <CodeAdapterSFML\SFMLFactory.h>




using namespace CodeAdapter;


int main()
{
	Factory::initializeInstance<SFMLFactory>();


	auto window1 = Factory::getInstance()->createWindow();
	window1->create(Drawing::Size(1024, 768),
		Utility::String("Hello, World!"));

	auto window2 = Factory::getInstance()->createWindow();
	window2->create(Drawing::Size(800, 600),
		Utility::String("Hello, World!?"));


	auto rect = std::make_shared<Drawing::DrawableRectangle>(-32, -64, 256, 128);
	rect->edgeColor = Drawing::Color::Magenta;
	rect->fillColor = Drawing::Color::Yellow;
	rect->edgeWidth = 8.0f;


	auto panel = std::make_shared<Drawing::Panel>();
	panel->transform.position = { 256, 256 };
	panel->size = { 1024, 768 };
	panel->addDrawable(rect);

	window1->addPanel(panel);
	window2->addPanel(panel);


	while (window1->isRunning() || window2->isRunning())
	{
		panel->transform.angle += 0.2f;


		if (window1->isRunning())
		{
			window1->update();
			window1->draw(Drawing::Color::Gray);
		}

		if (window2->isRunning())
		{
			window2->update();
			window2->draw(Drawing::Color::Gray);
		}
	}


	return 0;
}

