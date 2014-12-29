#pragma once

class Player {
public:
	Player();
	void init(int level, int health, int attack, int defense, int experience);

	// Setters
	void setPosition(int x, int y, int z);

	// Getters
	void getPosition(int &x, int &y, int &z);
};