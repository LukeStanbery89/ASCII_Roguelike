#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>

#include "GameSystem.h"

using namespace std;

int main() {
	GameSystem gameSystem("level1.txt");
	gameSystem.playGame();

	system("PAUSE");
	return 0;
}
