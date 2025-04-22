#pragma once
#include <string>
namespace ApplesGame {
	const std::string RESOURCES_PATH = "Resources/";

	const int SCREEN_WIDTH = 1100;
	const int SCREEN_HEIGHT = 770;
	const int APPLES_NUM = 25;
	const int BAD_APPLES_NUM = 15;
	const int LIVES = 3;
	const int START_SPEED = 170;

	const float PLAYER_SIZE = 32.f;
	const float GOLD_APPLE_SIZE = 40.f;
	const float GOLD_APPLE_SPEED = 200.f;
	const float APPLES_SIZE = 25.f;
	const float BAD_APPLES_SIZE = 70.f;

	//NOT FOR TOUCH
	const int SPEED_ON = 1;
	const int SPEED_OFF = 1 << 1;
	const int APPLES_INFINITE_ON = 1 << 2;
	const int APPLES_INFINITE_OFF = 1 << 3;
}