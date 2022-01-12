#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

void Enemy::attack(Player& p) {
	int x = std::rand() % 4;
	int y = x + damage;
	p.health -= y;
	std::cout << "Bob hit you for " << y << " damage! You now have " << p.health << " health!\n";
}
