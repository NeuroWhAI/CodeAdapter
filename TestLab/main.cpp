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


	auto texture1 = Factory::getInstance()->createTexture();
	texture1->loadFromFile("neurowhai.png");


	auto sprite1 = std::make_shared<Drawing::DrawableTexture>();
	sprite1->setTexture(texture1);
	sprite1->location.setLocation(-512.f, -512.f);
	sprite1->color = Drawing::Color(Drawing::Color::Red, 85);
	sprite1->transform.scale.setVector(0.5f, 0.5f);

	auto sprite2 = std::make_shared<Drawing::DrawableTexture>();
	sprite2->setTexture(texture1);
	sprite2->location.setLocation(-512.f + 16.f, -512.f);
	sprite2->color = Drawing::Color(Drawing::Color::Green, 85);
	sprite2->transform.scale.setVector(0.5f, 0.5f);

	auto sprite3 = std::make_shared<Drawing::DrawableTexture>();
	sprite3->setTexture(texture1);
	sprite3->location.setLocation(-512.f + 8.f, -512.f + 13.85f);
	sprite3->color = Drawing::Color(Drawing::Color::Blue, 85);
	sprite3->transform.scale.setVector(0.5f, 0.5f);

	auto sprite4 = std::make_shared<Drawing::DrawableTexture>();
	sprite4->setTexture(texture1);
	sprite4->location.setLocation(-512.f, -512.f);


	auto panel = std::make_shared<Drawing::Panel>();
	panel->transform.position = { 256, 256 };
	panel->size = { 1024, 768 };

	panel->addDrawable(sprite4);
	panel->addDrawable(sprite1);
	panel->addDrawable(sprite2);
	panel->addDrawable(sprite3);
	panel->addDrawable(rect);
	panel->addDrawable(ellipse);
	panel->addDrawable(ellipse2);
	panel->addDrawable(line1);
	panel->addDrawable(text1);

	window1->addPanel(panel);


	f32 myScale = 1.0f;
	f32 scaleDir = 1.0f;


	while (window1->isRunning())
	{
		myScale -= scaleDir * myScale / 64.0f;
		if (scaleDir > 0.0f && myScale < 0.1f)
		{
			scaleDir = -1.0f;
		}
		else if (scaleDir < 0.0f && myScale > 2.0f)
		{
			scaleDir = 1.0f;
		}

		sprite1->transform.scale.setVector(myScale, myScale);
		sprite2->transform.scale.setVector(myScale, myScale);
		sprite3->transform.scale.setVector(myScale, myScale);

		sprite4->transform.angle -= 0.4f;

		rect->transform.angle -= 0.3f;

		text1->transform.angle -= 0.1;

		panel->transform.angle += 0.2f;

		ellipse2->x += 0.2f;
		ellipse2->y += 0.4f;

		rect->setVisible(ellipse->containsPoint(ellipse2->x, ellipse2->y));


		window1->update();
		window1->draw(Drawing::Color::Gray);
	}


	return 0;
}

