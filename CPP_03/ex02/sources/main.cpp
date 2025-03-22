#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

void printDivider(const std::string& title) {
	std::cout << "\n===== " << title << " =====\n" << std::endl;
}

int main() {
	printDivider("FRAGTRAP CONSTRUCTION");

	FragTrap frag("Fraggy");
	FragTrap frag2(frag);
	FragTrap frag3("Placeholder");
	frag3 = frag;

	printDivider("BASIC STATS");

	std::cout << "Name: " << frag.getName() << std::endl;
	std::cout << "HP: " << frag.getHitPoints() << std::endl;
	std::cout << "Energy: " << frag.getEnergyPoints() << std::endl;
	std::cout << "Damage: " << frag.getAttackDamage() << std::endl;

	printDivider("ATTACK + DAMAGE TEST");

	frag.attack("BadBot");
	frag.takeDamage(40);
	frag.beRepaired(20);

	printDivider("HIGH FIVES TEST");

	frag.highFivesGuys();

	printDivider("DEATH & LIMIT TEST");

	frag.takeDamage(100);
	frag.attack("Nobody");
	frag.beRepaired(5);
	frag.highFivesGuys();

	printDivider("DESTRUCTION");

	return 0;
}
