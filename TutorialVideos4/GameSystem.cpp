#include "GameSystem.h"

// Constructor, sets up the game
GameSystem::GameSystem(string levelFile) {

	_player.init(1, 100, 10, 10, 0);

	_level.load(levelFile, _player);
	_level.print();

	system("PAUSE");
}

void GameSystem::playGame() {

	bool isDone = false;

	while(!isDone) {
		_level.print();
		playerMove();
	}
}

void GameSystem::playerMove() {
	char input;
	printf("Enter a move command (w/s/a/d): \n");
	input = _getch();

	_level.movePlayer(input, _player);
}