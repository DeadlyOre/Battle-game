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
		std::cout << "You defeated Bob! Gained 69 xp and $420!\n";
	}
	else if (winner == 2) {
		std::cout << "Bob defeated you... lost all your money!\n";
	}
	return 0;
}