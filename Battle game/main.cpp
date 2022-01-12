#include<iostream>
#include<cstdlib>
#include<string>
#include "Player.h"
#include "Enemy.h"

int main() {
	int winner = 0;
	int turn = 0;
	bool run = true;
	Player player;
	Enemy Bob;

	std::cout << "Enemy Bob appears! (100 health, 7 damage) Press enter to continue.\n";

	std::cin.get();

	//game loop
	while (run) {
		if (turn == 0) {
			if (player.health <= 0) {
				run = false;
				winner = 2;
				break;
			}
			else {
				player.menu(Bob);
				turn = 1;
				player.mana += 1;
				if (player.mana > 3) {
					player.mana = 3;
				}
			}
		}
		else if (turn == 1) {
			if (Bob.health <= 0) {
				run = false;
				winner = 1;
				break;
			}
			else {
				Bob.attack(player);
				turn = 0;
			}
		}
	}
	//ends game
	if (winner == 1) {
		std::cout << "\n!!You defeated Bob! Gained 69 xp and $420!!\n";
	}
	else if (winner == 2) {
		std::cout << "!!Bob defeated you... lost all your money!!\n";
	}

	std::cout << "\nPlease enter any character to exit the program\n";
	int x;
	//there was an issue and I'm not sure how else to fix it
	std::cin >> x;

	return 0;
}