#include <SFML/Graphics.hpp>
#include "SpinningCard.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Spinning card effect");
	window.setFramerateLimit(60);

	const std::string faceTextureFilename{ "G:/Resource Pool/images/misc/Kemqueen (110x150).jpg" };
	const std::string backTextureFilename{ "G:/Resource Pool/images/misc/BeeBack (110x150).jpg" };

	sf::Texture faceTexture;
	if (!faceTexture.loadFromFile(faceTextureFilename))
		return EXIT_FAILURE;
	faceTexture.setSmooth(true);
	sf::Sprite faceSprite(faceTexture);

	sf::Texture backTexture;
	if (!backTexture.loadFromFile(backTextureFilename))
		return EXIT_FAILURE;
	backTexture.setSmooth(true);
	sf::Sprite backSprite(backTexture);

	// set up and position cards
	const sf::Vector2f positionOfSpinningCard{ static_cast<float>(window.getSize().x) / 2, static_cast<float>(window.getSize().y) / 2 };
	faceSprite.setOrigin(faceSprite.getLocalBounds().width / 2, faceSprite.getLocalBounds().height / 2);
	backSprite.setOrigin(backSprite.getLocalBounds().width / 2, backSprite.getLocalBounds().height / 2);
	faceSprite.setPosition(positionOfSpinningCard);
	backSprite.setPosition(positionOfSpinningCard);
	faceSprite.setRotation(10);
	backSprite.setRotation(10);
	//faceSprite.setColor(sf::Color::Blue);
	//backSprite.setColor(sf::Color::Green);

	// prepare spinning card (one for face and one for back)
	hx::Misc::SpinningCard cardFace(faceSprite);
	hx::Misc::SpinningCard cardBack(backSprite);

	// spinDepth is depth of fake perspective is based on the size of the object (height when flipping horizontally, width when flipping vertically)
	// the higher the depth, the more "fake" it looks. if higher than 1, corners cross
	const float spinDepth{ 0.15f };
	cardFace.setDepth(spinDepth);
	cardBack.setDepth(spinDepth);

	// spin control
	bool doSpin{ false };
	const float anglePerSecond{ 521.21f };
	float spinAngle{ 0.f };
	const bool spinVertically{ false }; // spin horizontally (around the y axis) or vertically (around the x axis)
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					doSpin = true;
					clock.restart();
				}
			}
		}

		// update card spin
		if (doSpin)
		{
			spinAngle = clock.getElapsedTime().asSeconds() * anglePerSecond;
			if (spinAngle >= 360.f)
			{
				spinAngle = 0.f;
				doSpin = false;
			}
			if (spinVertically)
			{
				cardFace.spinVertically(spinAngle + 180); // show the face the correct way around
				cardBack.spinVertically(spinAngle);
			}
			else
			{
				cardFace.spin(spinAngle + 180); // show the face the correct way around
				cardBack.spin(spinAngle);
			}

			// smoothly move "out" when spinning
			const float scale{ 1.f + (0.5f * sin(spinAngle * 3.14159f / 360)) };
			cardFace.setScale(scale, scale);
			cardBack.setScale(scale, scale);
		}

		window.clear();

		// side cards (must return for the central card)
		backSprite.move(-120, 0);
		backSprite.rotate(-2);
		window.draw(backSprite);
		backSprite.move(240, 0);
		backSprite.rotate(4);
		window.draw(backSprite);
		backSprite.move(-120, 0);
		backSprite.rotate(-2);

		// central card
		if (doSpin)
		{
			if ((spinAngle > 90) && (spinAngle < 270))
				window.draw(cardFace);
			else
				window.draw(cardBack);
		}
		else
			window.draw(backSprite);

		window.display();
	}

	return 0;
}
