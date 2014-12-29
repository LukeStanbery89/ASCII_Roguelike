#pragma once
#include <iostream>
#include <string>
#include <conio.h>

#include "Player.h"
#include "Level.h"

using namespace std;

class GameSystem {
public:
	GameSystem(string levelFile);

	void playGame();
	void playerMove();

private:
	Player _player;
	Level _level;
};