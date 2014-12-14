#pragma once
#include <vector>
#include <string>

#include "Player.h"

using namespace std;

class Level {
public:
	Level();

	void load(string fileName, Player &player);
	void print();

private:
	vector <string> _levelData;
};
