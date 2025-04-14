#include "Game.h"
#include <string>
using namespace ApplesGame;

int main()
{
	//GAME INITIALIZATION
	int seed = time(nullptr);
	srand(seed);
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "AppelsGame");

	//Game
	Game game;
	GameInitialization(game);

	//TIME
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();
	
	while (window.isOpen())
	{
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		if  (game.gameState.state == State::Game) {
			//EVENT
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			//PLAYER LOGIC
			PlayerDirection(game.player);
			PlayerMove(game.player, deltaTime);
			PlayerCollisionWithWalls(game.player);
			PlayerCollisionWithApples(game, window);
			if (game.gameState.choice & 0b00001000) {
				if (game.apples.numApplesEaten == game.apples.numApples) {
					game.gameState.state = State::Restart;
				}
			}
			//GOLD APPLE LOGIC
			GoldAppleDirectionVoid(game.goldApple);
			GoldAppleMove(game.goldApple, deltaTime);
			MakeGoldAppleEat(game);

			//BAD APPLES
			PlayerCollisionWithBadApples(game);
			if (game.badApples.lives <= 0) {
				game.gameState.state = State::Restart;
			}


			//UPDATE
			game.LabelScore.message = "Score: " + std::to_string(Score);
			game.LabelScore.text.setString(game.LabelScore.message);

			game.LableSpeed.message = "SPEED: " + std::to_string(game.player.playerSpeed);
			game.LableSpeed.text.setString(game.LableSpeed.message);

			//DRAWING
			window.clear();
			BackGroundDraw(window,game.backGround);
			BadApplesDrawing(window, game.badApples);
			ApplesDrawin(window, game.apples, game.gameState);
			GoldAppleDrawing(window, game.goldApple);
			PlayerDraw(window, game.player);
			for (int i = 0; i < game.badApples.lives; ++i) {
				window.draw(game.hearts.HeartSprite[i]);
			}
			window.draw(game.LabelScore.text);
			window.draw(game.LableSpeed.text);
			window.display();
		}
		else if (game.gameState.state == State::MainMaiu) {
			MainMenuChoice(window, game.mainMenu, game.gameState);
		}
		else if (game.gameState.state == State::Restart) {
			RestartLoop(window, game.restart, game.gameState, game.player, game.apples, game.goldApple, game.badApples);
		}
	}
	return 0;
}