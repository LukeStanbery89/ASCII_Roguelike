#include <iostream>
#include <cstdio>
#include <conio.h>

#include "GameSystem.h"

// Constructor, sets up the game
GameSystem::GameSystem(string levelFileName) {

	_player.init(1, 100, 10, 10, 0);

	_level.load(levelFileName, _player);
	_level.print();

	system("PAUSE");
}

void GameSystem::playGame() {
	bool isDone = false;

	// Game Loop
	while(!isDone) {
		_level.print();
		playerMove();
	}
}

void GameSystem::playerMove() {
	char input;
	printf("Enter a move command (w/a/s/d): ");
	input = _getch();

	switch(input) {
		case 'w': // Up
		case 'W':
			break;
		case 's': // Down
		case 'S':
			break;
		case 'a': // Left
		case 'A':
			break;
		case 'd': // Right
		case 'D':
			break;
		default:
			printf("Invalid input!");
			system("PAUSE");
			break;
	}
}
