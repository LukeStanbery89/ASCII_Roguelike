#include "Level.h"

Level::Level() {
}

// Populates a level with data from a file
void Level::load(string fileName, Player &player) {

	// Loads the level
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
		for(int j = 0; j < _levelData[i].size(); j++) {
			tile = _levelData[i][j];

			switch(tile) {
				case '@':
					player.setPosition(j, i);
					break;
			}
		}
	}

}

void Level::print() {

	//cout << string(100,'n');
	system("cls");

	for(int i = 0; i < _levelData.size(); i++) {
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}

void Level::movePlayer(char input, Player &player) {

	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	switch(input) {
		case 'w': //up
		case 'W':
			processPlayerMove(player, playerX, playerY - 1);
			break;
		case 's': //down
		case 'S':
			processPlayerMove(player, playerX, playerY + 1);
			break;
		case 'a': //left
		case 'A':
			processPlayerMove(player, playerX - 1, playerY);
			break;
		case 'd': //right
		case 'D':
			processPlayerMove(player, playerX + 1, playerY);
			break;
		default:
			printf("INVALID INPUT!\n");
			system("PAUSE");
			break;
	}
}

char Level::getTile(int x, int y) {
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile) {
	_levelData[y][x] = tile;
}

void Level::processPlayerMove(Player &player, int targetX, int targetY) {
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	char moveTile = getTile(targetX, targetY);

	switch(moveTile) {
		case '#':
			printf("You ran into a wall!\n");
			system("PAUSE");
			break;
		case '.':
			player.setPosition(targetX, targetY);
			setTile(playerX, playerY, '.');
			setTile(targetX, targetY, '@');
			break;
	}
}