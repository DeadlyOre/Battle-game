#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <cstdlib>



void Player::menu(Enemy& e) {
	bool myTurn = true;
	while (myTurn) {

		std::cout << "You have " << health << " health and " << mana << " mana. Please select an action (1:attack 2:spells 3:stats)\n";
		std::string menu1;
		std::cin >> menu1;

		if (menu1 == "1") {
			int x = std::rand() % 4;
			int y = x + damage;
			e.health -= y;
			std::cout << "Bob was hit for " << y << " damage. Bob now has " << e.health << " health.\n";
			myTurn = false;
			break;
		}
		//spell menu
		else if (menu1 == "2") {
			std::cout << "Please pick a spell [1:Fireball(2 mana) 2:Heal(3 mana) b:back]\n";
			std::string menu2;
			std::cin >> menu2;

			if (menu2 == "1") {
				if (mana >= 2) {
					mana -= 2;
					int x = std::rand() % 6;
					int y = x + sDamage;
					e.health -= y;
					std::cout << "Bob succesfully hit for " << y << " damage! Bob now has " << e.health << " health.\n";
					myTurn = false;
					break;
				}
				else {
					std::cout << "Not enough mana\n";
				}
			}
			else if (menu2 == "2") {
				if (mana == 3) {
					health += 15;
					mana -= 3;
					if (health > 100) {
						health = 100;
					}
					std::cout << "Successfully healed for 15 health! You now have " << health << " health!\n";
					myTurn = false;
					break;
				}
				else {
					std::cout << "Not enough mana\n";
				}
			}
			else if (menu2 == "b") {

			}
			else {
				std::cout << "Please enter a valid command\n";
			}
		}
		else if (menu1 == "3") {
			std::cout << "PLAYER STATS:\n";
			std::cout << "\n";
			std::cout << "MAX HEALTH: 100\n";
			std::cout << "HEALTH: " << health << std::endl;
			std::cout << "MAX MANA: 3\n";
			std::cout << "MANA: " << mana << std::endl;
			std::cout << "DAMAGE: 5\n";
			std::cout << "SPELL DAMAGE: 15\n";
		}
		else {
			std::cout << "Please enter a valid command\n";
		}
	}
}

