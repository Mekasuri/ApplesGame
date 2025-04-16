#include "MainGameLoop.h"
namespace ApplesGame {
	void PlayerLogic(sf::RenderWindow& window, Game& game, float deltaTime) {
		PlayerDirection(game.player);
		PlayerMove(game.player, deltaTime);
		PlayerCollisionWithWalls(game.player);
		PlayerCollisionWithApples(game, window);
		if (game.gameState.choice & APPLES_INFINITE_OFF) {
			if (game.apples.numApplesEaten == game.apples.numApples) {
				game.gameState.state = State::Restart;
			}
		}
	}
	void GoldAppleLogic(Game& game, float deltaTime) {
		GoldAppleDirectionVoid(game.goldApple);
		GoldAppleMove(game.goldApple, deltaTime);
		MakeGoldAppleEat(game);
	}
	void BadApplesLogic(Game& game) {
		PlayerCollisionWithBadApples(game);
		if (game.badApples.lives <= 0) {
			game.gameState.state = State::Restart;
		}
	}
	void InterfaceUpdate(Game& game) {
		game.LabelScore.message = "Score: " + std::to_string(Score);
		game.LabelScore.text.setString(game.LabelScore.message);

		game.LableSpeed.message = "SPEED: " + std::to_string(game.player.playerSpeed);
		game.LableSpeed.text.setString(game.LableSpeed.message);
	}
	void Drawing(sf::RenderWindow& window, Game& game) {
		window.clear();
		BackGroundDraw(window, game.backGround);
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

	void GeneralGameLogic(sf::RenderWindow& window, Game& game, float deltaTime) {
		PlayerLogic(window, game, deltaTime);
		GoldAppleLogic(game, deltaTime);
		BadApplesLogic(game);
		InterfaceUpdate(game);
		Drawing(window, game);
	}
}