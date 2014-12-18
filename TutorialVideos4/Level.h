#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>

#include "Player.h"

using namespace std;

class Level {
public:
	Level();

	void load(string fileName, Player &player);
	void print();

	void movePlayer(char input, Player &player);

	// Getters
	char getTile(int x, int y);

	// Setters
	void setTile(int x, int y, char tile);

private:
	vector <string> _levelData;

	void processPlayerMove(Player &player, int targetX, int targetY);
};
