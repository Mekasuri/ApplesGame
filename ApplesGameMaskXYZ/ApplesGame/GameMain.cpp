#include "MainGameLoop.h"
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
	
	while (window.isOpen()){
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
			GeneralGameLogic(window, game, deltaTime);
		}
		else if (game.gameState.state == State::MainManu) {
			MainMenuChoice(window, game.mainMenu, game.gameState);
		}
		else if (game.gameState.state == State::Restart) {
			RestartLoop(window, game.restart, game.gameState, game.player, game.apples, game.goldApple, game.badApples);
		}
	}
	return 0;
}