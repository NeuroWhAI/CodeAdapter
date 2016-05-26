#include <CodeAdapter\EasyCA.h>
#include <CodeAdapterSFML\SFMLFactory.h>




int main()
{
	initializeCA<SFMLFactory>();


	i32 button1ClickCount = 0;


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
	font1->setStyle(caDraw::FontStyles::Bold);


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


	auto label1 = canew<caUI::Label>();
	label1->setFont(font1);
	label1->setText(L"label text");
	label1->setTextMargin({ 8, 0 });
	label1->setBackColor(caDraw::Color::Gray);
	label1->setPosition({ 128, 128 });
	label1->setSize({ 330, 100 });
	label1->setSelectable(true);
	label1->WhenTouchDown = [&label1](const caUI::TouchEventArgs& args) {
		label1->setTextColor(caDraw::Color::Red);
		label1->setPosition({ static_cast<f32>(args.x) - 165,
			static_cast<f32>(args.y) - 50 });
	};
	label1->WhenTouchUp = [&label1](const caUI::TouchEventArgs& args) {
		label1->setTextColor(caDraw::Color::Black);
	};
	label1->WhenEnterFocus = [&label1](const caUI::EventArgs& args) {
		label1->setTextColor(caDraw::Color::Blue);
	};
	label1->WhenLeaveFocus = [&label1](const caUI::EventArgs& args) {
		label1->setTextColor(caDraw::Color::Black);
	};
	label1->WhenSelected = [&label1](const caUI::EventArgs& args) {
		label1->setBackColor(caDraw::Color::White);
	};
	label1->WhenDeselected = [&label1](const caUI::EventArgs& args) {
		label1->setBackColor(caDraw::Color::Gray);
	};
	label1->WhenKeyDown = [&label1](const caUI::KeyEventArgs& args) {
		switch (args.key)
		{
		case caSys::Keys::Space:
			label1->setPosition({ 128, 128 });
			break;
		}
	};

	auto label2 = canew<caUI::Label>(*label1);
	label2->WhenTouchDown = [&label2](const caUI::TouchEventArgs& args) {
		label2->setTextColor(caDraw::Color::Red);
		label2->setPosition({ static_cast<f32>(args.x) - 165,
			static_cast<f32>(args.y) - 50 });
	};
	label2->WhenTouchUp = [&label2](const caUI::TouchEventArgs& args) {
		label2->setTextColor(caDraw::Color::Black);
	};
	label2->WhenEnterFocus = [&label2](const caUI::EventArgs& args) {
		label2->setTextColor(caDraw::Color::Blue);
	};
	label2->WhenLeaveFocus = [&label2](const caUI::EventArgs& args) {
		label2->setTextColor(caDraw::Color::Black);
	};
	label2->WhenSelected = [&label2](const caUI::EventArgs& args) {
		label2->setBackColor(caDraw::Color::White);
	};
	label2->WhenDeselected = [&label2](const caUI::EventArgs& args) {
		label2->setBackColor(caDraw::Color::Gray);
	};
	label2->WhenKeyDown = [&label2](const caUI::KeyEventArgs& args) {
		switch (args.key)
		{
		case caSys::Keys::Space:
			label2->setPosition({ 128, 128 });
			break;
		}
	};


	auto button1 = canew<caUI::Button>();
	button1->setFont(font1);
	button1->setText(L"button1");
	button1->setBackColor(caDraw::Color::Gray);
	button1->setPosition({ 128, 300 });
	button1->setSize({ 330, 100 });
	button1->WhenClick = [&button1ClickCount, &label1](const caUI::EventArgs& args)
	{
		++button1ClickCount;

		label1->setText(std::to_string(button1ClickCount));
	};


	auto verticalScrollBar1 = canew<caUI::VerticalScrollBar>();
	verticalScrollBar1->setPosition({ 750, 32 });
	verticalScrollBar1->setSize({24, 256});
	verticalScrollBar1->setMaxValue(1024);
	verticalScrollBar1->WhenValueChanged = [&verticalScrollBar1, &label2](const caUI::EventArgs& args)
	{
		label2->setText(std::to_string(verticalScrollBar1->getValue()));
	};


	auto horizontalScrollBar1 = canew<caUI::HorizontalScrollBar>();
	horizontalScrollBar1->setPosition({ 420, 256 });
	horizontalScrollBar1->setSize({ 256, 24 });
	horizontalScrollBar1->setMaxValue(256);
	horizontalScrollBar1->setMinBarLength(32);
	horizontalScrollBar1->WhenValueChanged = [&horizontalScrollBar1, &verticalScrollBar1](const caUI::EventArgs& args)
	{
		verticalScrollBar1->setMaxValue(horizontalScrollBar1->getValue());
	};

	verticalScrollBar1->setMaxValue(horizontalScrollBar1->getValue());


	auto textbox1 = canew<caUI::TextBox>();
	textbox1->setFont(font1);
	textbox1->setTextMargin({ 8, 8 });
	textbox1->setBackColor(caDraw::Color::Gray);
	textbox1->setPosition({ 64, 420 });
	textbox1->setSize({ 330, 100 });


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
	panel->addDrawable(label1);
	panel->addUpdatable(label1);
	panel->addDrawable(button1);
	panel->addUpdatable(button1);
	panel->addDrawable(verticalScrollBar1);
	panel->addUpdatable(verticalScrollBar1);
	panel->addDrawable(horizontalScrollBar1);
	panel->addUpdatable(horizontalScrollBar1);
	panel->addDrawable(textbox1);
	panel->addUpdatable(textbox1);

	window1->addPanel(panel);


	auto panel2 = caFactory->createPanel();
	panel2->transform.position = { 600, 400 };
	panel2->size = { 400, 300 };

	panel2->addDrawable(sprite4);
	panel2->addDrawable(sprite1);
	panel2->addDrawable(sprite2);
	panel2->addDrawable(sprite3);
	panel2->addDrawable(rect);
	panel2->addDrawable(ellipse);
	panel2->addDrawable(line1);
	panel2->addDrawable(text1);
	panel2->addDrawable(label2);
	panel2->addUpdatable(label2);

	window1->addPanel(panel2);


	f32 myScale = 1.0f;
	f32 scaleDir = 1.0f;


	while (window1->isRunning())
	{
		caTouch->update();


		caKeyboard->update(*window1);

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

		panel2->transform.angle += 0.02f;


		rect->setVisible(ellipse->containsPoint(ellipse2->x, ellipse2->y));


		auto invPoint = panel2->transform.inverseTransformPoint(caTouch->getPositionF(*window1));
		ellipse2->setLocation(invPoint.x, invPoint.y);


		if (label1->isFocused())
		{
			label1->setPosition(label1->getPosition() + caDraw::PointF(0.4f, 0.0f));
		}

		if (label2->isFocused())
		{
			label2->setPosition(label2->getPosition() + caDraw::PointF(0.4f, 0.0f));
		}


		caSys::WindowEvent newEvent;
		if (window1->update(&newEvent))
		{
			if (newEvent.getType() == caSys::WindowEvent::Types::Resized)
			{
				label1->setText(std::to_wstring(newEvent.size.width) +
					L"x" + std::to_wstring(newEvent.size.height));
			}
		}

		window1->draw(caDraw::Color(230, 230, 230));
	}


	return 0;
}

