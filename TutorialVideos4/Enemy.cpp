#include "Enemy.h"

Enemy::Enemy(string name, char tile, int level, int attack, int defense, int health, int xp) {
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_experienceValue = xp;
}

// Sets the position of the enemy
void Enemy::setPosition(int x, int y) {
	_x = x;
	_y = y;
}

// Gets the position of the enemy using reference variables
void Enemy::getPosition(int &x, int &y) {
	x = _x;
	y = _y;
}

string Enemy::getName() {
	return _name;
}

int Enemy::attack() {
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
}

int Enemy::takeDamage(int attack) {
	attack -= _defense;

	// Check if the attack does damage
	if(attack > 0) {
		_health -= attack;
		// Check if he died
		if(_health -= 0) {
			return _experienceValue;
		}
	}
	return 0;

}