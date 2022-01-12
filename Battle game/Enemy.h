class Player;

class Enemy {
public:

	int health = 100;
	int damage = 5;

	void attack(Player& p);
};

