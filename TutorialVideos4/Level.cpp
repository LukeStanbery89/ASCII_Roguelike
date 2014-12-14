#include <fstream>
#include <iostream>
#include <cstdio>

#include "Level.h"

Level::Level() {
}

// Loads the level into the game from a file
void Level::load(string fileName, Player &player) {

	ifstream file;

	file.open(fileName);
	if(file.fail()) {
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;

	while(getline(file, line)) {
		_levelData.push_back(line);
	}

	file.close();

	// Process the level
	char tile;
	for(int i = 0; i < _levelData.size(); i++) {
		for(int j = 0; j < _levelData.size(); j++) {
			tile = _levelData[i][j];

			switch(tile) {
				case '@':
					player.setPosition(j, i);
					break;
			}
		}
	}
}

// Prints out the level to the screen
void Level::print() {

	cout << string(100, "\n");

	for(int i = 0; i < _levelData.size(); i++) {
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}
