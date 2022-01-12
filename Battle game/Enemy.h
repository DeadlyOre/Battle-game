#pragma once

class Player;

class Enemy {
public:

	int health = 100;
	const int damage = 7;

	void attack(Player& p);
};

