#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void printDivider(const std::string& title) {
	std::cout << "\n===== " << title << " =====\n" << std::endl;
}

int main() {
	printDivider("SCAVTRAP CONSTRUCTION TESTS");

	ScavTrap scav("Scavy");
	ScavTrap another(scav); // Copy constructor
	ScavTrap copy;
	copy = scav; // Assignment

	printDivider("SCAVTRAP BASIC STATS");

	std::cout << "Name: " << scav.getName() << std::endl;
	std::cout << "HP: " << scav.getHitPoints() << std::endl;
	std::cout << "Energy: " << scav.getEnergyPoints() << std::endl;
	std::cout << "Damage: " << scav.getAttackDamage() << std::endl;

	printDivider("ATTACK TEST");

	scav.attack("target dummy");

	printDivider("DAMAGE / REPAIR TEST");

	scav.takeDamage(25);
	scav.beRepaired(10);
	scav.takeDamage(85); // Should bring it to 0
	scav.beRepaired(5);  // Should not work
	scav.attack("Ghost"); // Should not work

	printDivider("GUARD GATE MODE");

	another.guardGate();

	printDivider("DESTRUCTION");

	return 0;
}
