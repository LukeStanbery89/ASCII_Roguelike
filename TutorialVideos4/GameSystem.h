#pragma once
#include <iostream>
#include <string>
#include <conio.h>

#include "Level.h"
#include "Player.h"

using namespace std;

class GameSystem {
public:
	GameSystem(string levelFile);

	void playGame();
	void playerMove();

private:
	Level _level;
	Player _player;
};
