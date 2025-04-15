#include "MainMenu.h"
#include "Math.h"
#include <cassert>
namespace ApplesGame {
	void MainMenuInitialization(MainMenu& mainMenuBackGround) {
		assert(mainMenuBackGround.MainBackGroundTexture.loadFromFile(RESOURCES_PATH + "/MainBackGround.png"));
		mainMenuBackGround.MainBackGroundSprite.setTexture(mainMenuBackGround.MainBackGroundTexture);
		mainMenuBackGround.MainBackGroundSprite.setPosition(mainMenuBackGround.MainBackGrountPosition.x, mainMenuBackGround.MainBackGrountPosition.y);
		SetSpriteSize(mainMenuBackGround.MainBackGroundSprite, SCREEN_WIDTH, SCREEN_HEIGHT);
		SetSprieOrigin(mainMenuBackGround.MainBackGroundSprite, 0.5, 0.5);

		mainMenuBackGround.SpeedChoiceShape.setFillColor(sf::Color::Green);
		mainMenuBackGround.SpeedChoiceShape.setRadius(13);
		mainMenuBackGround.SpeedChoiceShape.setPosition(mainMenuBackGround.SpeedChoisePosition.x, mainMenuBackGround.SpeedChoisePosition.y);

		mainMenuBackGround.ApplesChoiceShape.setFillColor(sf::Color::Green);
		mainMenuBackGround.ApplesChoiceShape.setRadius(13);
		mainMenuBackGround.ApplesChoiceShape.setPosition(mainMenuBackGround.ApplesChoisePosition.x, mainMenuBackGround.ApplesChoisePosition.y);
		mainMenuBackGround.online = static_cast<int>(10 + std::round(rand() / (float)RAND_MAX * 10000));



		mainMenuBackGround.OnlineLabel.position.x = 790;
		mainMenuBackGround.OnlineLabel.position.y = 730;
		mainMenuBackGround.OnlineLabel.color = sf::Color::Green;
		mainMenuBackGround.OnlineLabel.message = "Online now: " + std::to_string(mainMenuBackGround.online);
		LableInitialization(mainMenuBackGround.OnlineLabel);

		SoundInitialization(mainMenuBackGround.ClickSound, "/ClickSound.wav");
	}

	void MainMenuChoice(sf::RenderWindow& window,MainMenu& mainMenuBackGround, GameState& gameState) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		if (gameState.state == State::MainMaiu) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) {
				//mainMenuBackGround.ClickSound.sound.play();
					
				gameState.choice = gameState.choice | 0b00000001;

				gameState.choice = gameState.choice & ~0b00000010;

				mainMenuBackGround.SpeedChoisePosition.y = 150;
				mainMenuBackGround.SpeedChoisePosition.x = 265;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) {
				//mainMenuBackGround.ClickSound.sound.play();

				gameState.choice = gameState.choice | 0b00000010;

				gameState.choice = gameState.choice & ~0b00000001;

				mainMenuBackGround.SpeedChoisePosition.y = 232;
				mainMenuBackGround.SpeedChoisePosition.x = 290;

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) {
				//mainMenuBackGround.ClickSound.sound.play();

				gameState.choice = gameState.choice | 0b00000100;

				gameState.choice = gameState.choice & ~0b00001000;

				mainMenuBackGround.ApplesChoisePosition.y = 310;
				mainMenuBackGround.ApplesChoisePosition.x = 520;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)) {
				//mainMenuBackGround.ClickSound.sound.play();

				gameState.choice = gameState.choice | 0b00001000;

				gameState.choice = gameState.choice & ~0b00000100;

				mainMenuBackGround.ApplesChoisePosition.y = 385;
				mainMenuBackGround.ApplesChoisePosition.x = 540;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5)) {
				mainMenuBackGround.ClickSound.sound.play();
				gameState.state = State::Restart;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				mainMenuBackGround.ClickSound.sound.play();
				window.close();
				return;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				gameState.state = State::Game;
			}
			mainMenuBackGround.SpeedChoiceShape.setPosition(mainMenuBackGround.SpeedChoisePosition.x, mainMenuBackGround.SpeedChoisePosition.y);
			mainMenuBackGround.ApplesChoiceShape.setPosition(mainMenuBackGround.ApplesChoisePosition.x, mainMenuBackGround.ApplesChoisePosition.y);
			window.clear();
			window.draw(mainMenuBackGround.MainBackGroundSprite);
			window.draw(mainMenuBackGround.OnlineLabel.text);
			window.draw(mainMenuBackGround.SpeedChoiceShape);
			window.draw(mainMenuBackGround.ApplesChoiceShape);
			window.display();
		}
	}
}