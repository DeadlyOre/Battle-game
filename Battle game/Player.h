class Enemy;

class Player {
public:

	//player varialbes
	int health = 100;
	int mana = 0;
	const int damage = 5;
	const int sDamage = 15;

	//handling menus
	void menu(Enemy& e);
};

