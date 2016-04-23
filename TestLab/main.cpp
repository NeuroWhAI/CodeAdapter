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


	auto line1 = std::make_shared<Drawing::DrawableLine>(rect->x,
		rect->y, rect->x + rect->width, rect->y + rect->height);
	line1->color = Drawing::Color::Cyan;
	line1->thickness = 8.0f;


	auto font1 = Factory::getInstance()->createFont();
	font1->loadFromFile("ÀÕ°ÉÃ¼.ttf");
	font1->setCharacterSize(64);
	font1->setStyle(Drawing::FontStyles::StrikeOut | Drawing::FontStyles::Bold);


	auto text1 = std::make_shared<Drawing::DrawableText>();
	text1->setFont(font1);
	text1->text = L"Hello, World!\n¾È³ç ¼¼»ó¾Æ!";
	text1->location.setLocation(-64, -8);
	text1->color = Drawing::Color(34, 177, 76);


	auto panel = std::make_shared<Drawing::Panel>();
	panel->transform.position = { 256, 256 };
	panel->size = { 1024, 768 };

	panel->addDrawable(rect);
	panel->addDrawable(ellipse);
	panel->addDrawable(ellipse2);
	panel->addDrawable(line1);
	panel->addDrawable(text1);

	window1->addPanel(panel);


	while (window1->isRunning())
	{
		panel->transform.angle += 0.2f;

		ellipse2->x += 0.2f;
		ellipse2->y += 0.4f;

		rect->setVisible(ellipse->containsPoint(ellipse2->x, ellipse2->y));


		window1->update();
		window1->draw(Drawing::Color::Gray);
	}


	return 0;
}

