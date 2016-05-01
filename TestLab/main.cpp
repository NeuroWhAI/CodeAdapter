#include <CodeAdapter\EasyCA.h>
#include <CodeAdapterSFML\SFMLFactory.h>




int main()
{
	initializeCA<SFMLFactory>();


	auto window1 = caFactory->createWindow();
	window1->create(caDraw::Size(1024, 768), caUtil::String("Hello, World!"));


	auto rect = canew<caDraw::DrawableRectangle>(-32, -64, 256, 128);
	rect->edgeColor = caDraw::Color::Magenta;
	rect->fillColor = caDraw::Color::Yellow;
	rect->edgeWidth = 8.0f;


	auto ellipse = canew<caDraw::DrawableEllipse>(-32, -64, 256, 128);
	ellipse->edgeColor = caDraw::Color::Yellow;
	ellipse->fillColor = caDraw::Color::Magenta;
	ellipse->edgeWidth = 2.0f;


	auto ellipse2 = canew<caDraw::DrawableEllipse>(-40, -70, 2, 2);
	ellipse2->edgeColor = caDraw::Color::Red;
	ellipse2->fillColor = caDraw::Color::Red;
	ellipse2->edgeWidth = 1.0f;


	auto line1 = canew<caDraw::DrawableLine>(rect->x, rect->y,
		rect->x + rect->width, rect->y + rect->height);
	line1->color = caDraw::Color::Cyan;
	line1->thickness = 8.0f;


	auto font1 = caFactory->createFont();
	font1->loadFromFile("NanumGothic.ttf");
	font1->setCharacterSize(64);
	font1->setStyle(caDraw::FontStyles::Underline | caDraw::FontStyles::Bold);


	auto text1 = canew<caDraw::DrawableText>();
	text1->setFont(font1);
	text1->text = L"Hello, World!\n¾È³ç ¼¼»ó¾Æ!";
	text1->location.setLocation(64, 8);
	text1->color = caDraw::Color(34, 177, 76);


	auto texture1 = caFactory->createTexture();
	texture1->loadFromFile("neurowhai.png");


	auto sprite1 = canew<caDraw::DrawableTexture>();
	sprite1->setTexture(texture1);
	sprite1->location.setLocation(-512.f, -512.f);
	sprite1->color = caDraw::Color(caDraw::Color::Red, 85);
	sprite1->transform.scale.setVector(0.5f, 0.5f);

	auto sprite2 = canew<caDraw::DrawableTexture>();
	sprite2->setTexture(texture1);
	sprite2->location.setLocation(-512.f + 16.f, -512.f);
	sprite2->color = caDraw::Color(caDraw::Color::Green, 85);
	sprite2->transform.scale.setVector(0.5f, 0.5f);

	auto sprite3 = canew<caDraw::DrawableTexture>();
	sprite3->setTexture(texture1);
	sprite3->location.setLocation(-512.f + 8.f, -512.f + 13.85f);
	sprite3->color = caDraw::Color(caDraw::Color::Blue, 85);
	sprite3->transform.scale.setVector(0.5f, 0.5f);

	auto sprite4 = canew<caDraw::DrawableTexture>();
	sprite4->setTexture(texture1);
	sprite4->location.setLocation(-512.f, -512.f);


	auto panel = caFactory->createPanel();
	panel->transform.position = { 64, 64 };
	panel->size = { 800, 600 };

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


	auto panel2 = caFactory->createPanel();
	panel2->transform.position = { 512, 400 };
	panel2->size = { 400, 300 };

	panel2->addDrawable(sprite4);
	panel2->addDrawable(sprite1);
	panel2->addDrawable(sprite2);
	panel2->addDrawable(sprite3);
	panel2->addDrawable(rect);
	panel2->addDrawable(ellipse);
	panel2->addDrawable(ellipse2);
	panel2->addDrawable(line1);
	panel2->addDrawable(text1);

	window1->addPanel(panel2);


	f32 myScale = 1.0f;
	f32 scaleDir = 1.0f;


	while (window1->isRunning())
	{
		caTouch->update();

		if (caTouch->isPressed())
		{
			panel2->transform.position = caTouch->getPositionF(*window1);
		}


		caKeyboard->update();

		if (caKeyboard->isKeyPressed(caSys::Keys::W))
		{
			ellipse2->y -= 0.4f;
		}
		else if (caKeyboard->isKeyPressed(caSys::Keys::S))
		{
			ellipse2->y += 0.4f;
		}

		if (caKeyboard->isKeyPressed(caSys::Keys::A))
		{
			ellipse2->x -= 0.4f;
		}
		else if (caKeyboard->isKeyPressed(caSys::Keys::D))
		{
			ellipse2->x += 0.4f;
		}


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

		text1->transform.angle -= 0.1f;

		panel->transform.angle += 0.2f;
		panel2->transform.angle += 0.2f;


		rect->setVisible(ellipse->containsPoint(ellipse2->x, ellipse2->y));


		window1->update();
		window1->draw(caDraw::Color::Gray);
	}


	return 0;
}

