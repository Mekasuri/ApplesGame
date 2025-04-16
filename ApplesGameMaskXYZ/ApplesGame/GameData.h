#pragma once
namespace ApplesGame {
	extern int Score;
	enum class State {
		MainManu = 0,
		Restart,
		Game,
	};
	struct GameState {
		State state;
		int choice = 0b00000101;
		bool ExitDialog = false;
	};
	enum class Direction {
		Right = 0,
		Up,
		Left,
		Down
	};
	struct Position2D {
		float x;
		float y;
	};
}
