#include "DiamondTrap.hpp"
#include <iostream>

void printDivider(const std::string& title) {
	std::cout << "\n===== " << title << " =====\n" << std::endl;
}

int main() {
	printDivider("DIAMONDTRAP CONSTRUCTION");

	DiamondTrap d1("Shiny");
	DiamondTrap d2(d1); // Copy constructor
	DiamondTrap d3("Placeholder");
	d3 = d1; // Assignment

	printDivider("STATS CHECK");

	std::cout << "Name: " << d1.getName() << std::endl;
	std::cout << "HP: " << d1.getHitPoints() << std::endl;
	std::cout << "Energy: " << d1.getEnergyPoints() << std::endl;
	std::cout << "Damage: " << d1.getAttackDamage() << std::endl;

	printDivider("ATTACK TEST");

	d1.attack("FinalBoss"); // Should use ScavTrap's attack()

	printDivider("WHO AM I TEST");

	d1.whoAmI();

	printDivider("DAMAGE + REPAIR");

	d1.takeDamage(40);
	d1.beRepaired(15);
	d1.takeDamage(75); // Kill it
	d1.attack("Ghost"); // Should not work
	d1.beRepaired(10); // Should not work
	d1.whoAmI();        // Should still work

	printDivider("SPECIAL ABILITIES INHERITED");

	d2.highFivesGuys(); // From FragTrap
	d2.guardGate();     // From ScavTrap

	printDivider("DESTRUCTION");

	return 0;
}
