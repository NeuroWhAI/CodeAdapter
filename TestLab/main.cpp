#include <CodeAdapter\CodeAdapter.h>
#include <CodeAdapterSFML\SFMLFactory.h>




using namespace CodeAdapter;


int main()
{
	Factory::initializeInstance<SFMLFactory>();


	auto window1 = Factory::getInstance()->createWindow();
	window1->create(Drawing::Size(1024, 768),
		Utility::String("Hello, World!"));


	auto rect = std::make_shared<Drawing::DrawableRectangle>(-32, -64, 256, 128);
	rect->edgeColor = Drawing::Color::Magenta;
	rect->fillColor = Drawing::Color::Yellow;
	rect->edgeWidth = 8.0f;


	auto ellipse = std::make_shared<Drawing::DrawableEllipse>(-32, -64, 256, 128);
	ellipse->edgeColor = Drawing::Color::Yellow;
	ellipse->fillColor = Drawing::Color::Magenta;
	ellipse->edgeWidth = 2.0f;


	auto ellipse2 = std::make_shared<Drawing::DrawableEllipse>(-40, -70, 2, 2);
	ellipse2->edgeColor = Drawing::Color::Red;
	ellipse2->fillColor = Drawing::Color::Red;
	ellipse2->edgeWidth = 1.0f;


	auto panel = std::make_shared<Drawing::Panel>();
	panel->transform.position = { 256, 256 };
	panel->size = { 1024, 768 };

	panel->addDrawable(rect);
	panel->addDrawable(ellipse);
	panel->addDrawable(ellipse2);

	window1->addPanel(panel);


	while (window1->isRunning())
	{
		panel->transform.angle += 0.02f;

		ellipse2->x += 0.02;
		ellipse2->y += 0.04;

		rect->setVisible(ellipse->containsPoint(ellipse2->x, ellipse2->y));


		window1->update();
		window1->draw(Drawing::Color::Gray);
	}


	return 0;
}

