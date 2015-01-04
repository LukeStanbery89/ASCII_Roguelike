#include "Level.h"

Level::Level() {

}

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
				case '@': //Player
					player.setPosition(j, i);
					break;
				case 'S': //Snake
					_enemies.push_back(Enemy("Snake", tile, 1, 3, 1, 10, 50));
					_enemies.back().setPosition(j, i);
					break;
				case 'G': //Goblin
					_enemies.push_back(Enemy("Goblin", tile, 2, 10, 5, 35, 150));
					_enemies.back().setPosition(j, i);
					break;
				case 'O': //Ogre
					_enemies.push_back(Enemy("Goblin", tile, 4, 20, 40, 200, 500));
					_enemies.back().setPosition(j, i);
					break;
				case 'D': //Dragon
					_enemies.push_back(Enemy("Dragon", tile, 100, 2000, 2000, 2000, 50000000));
					_enemies.back().setPosition(j, i);
					break;
				case 'B': //Bandit
					_enemies.push_back(Enemy("Bandit", tile, 3, 15, 10, 100, 250));
					_enemies.back().setPosition(j, i);
					break;
			}
		}
	}
}

void Level::print() {

	// Clears the screen
	system("cls");

	for(int i = 0; i < _levelData.size(); i++) {
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}

// Moves the player
void Level::movePlayer(char input, Player &player) {

	int playerX;
	int playerY;

	player.getPosition(playerX, playerY);

	switch(input) {
		case 'w': //Up
		case 'W':
			processPlayerMove(player, playerX, playerY - 1);
			break;
		case 's': //Down
		case 'S':
			processPlayerMove(player, playerX, playerY + 1);
			break;
		case 'a': //Left
		case 'A':
			processPlayerMove(player, playerX - 1, playerY);
			break;
		case 'd': //Right
		case 'D':
			processPlayerMove(player, playerX + 1, playerY);
			break;
		default:
			printf("INVALID INPUT!\N");
			system("PAUSE");
			break;
	}
}

// Gets the tile at a specified location
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
		case '.':
			player.setPosition(targetX, targetY);
			setTile(playerX, playerY, '.');
			setTile(targetX, targetY, '@');
			break;
		case '#':
			break;
			// Place monsters here:
		default:
			battleMonster(player, targetX, targetY);
			break;
	}
}

void Level::battleMonster(Player &player, int targetX, int targetY) {

	int enemyX;
	int enemyY;
	int playerX;
	int playerY;
	int attackRoll;
	int attackResult;
	string enemyName;

	player.getPosition(playerX, playerY);

	for(int i = 0; i < _enemies.size(); i++) {

		_enemies[i].getPosition(enemyX, enemyY);
		enemyName = _enemies[i].getName();

		if(targetX == enemyX && targetY == enemyY) {

			// Battle!
			attackRoll = player.attack();
			printf("Player attacked %s with a roll of %d\n", enemyName.c_str(), attackRoll);
			attackResult = _enemies[i].takeDamage(attackRoll);

			if(attackResult != 0) {
				setTile(targetX, targetY, '.');
				print();
				printf("Monster died!\n");
				system("PAUSE");
				player.addExperience(attackResult);

				return;
			}

			// Monster's turn
			attackRoll = _enemies[i].attack();
			printf("%s attacked monster with a roll of %d\n", enemyName.c_str(), attackRoll);
			attackResult = player.takeDamage(attackRoll);

			if(attackResult != 0) {
				setTile(playerX, playerY, 'x');
				print();
				printf("You died!\n");
				system("PAUSE");

				exit(0);
			}
			system("PAUSE");
			return;
		}
	}

}