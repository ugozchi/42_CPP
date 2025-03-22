#include "ClapTrap.hpp"
#include <iostream>
#include <string>

void printDivider(const std::string& title) {
	std::cout << "\n===== " << title << " =====\n" << std::endl;
}

int main() {
	printDivider("CONSTRUCTION TESTS");

    ClapTrap	somebody;
	ClapTrap robotA("Alpha");
	ClapTrap robotB("Beta");

	printDivider("ATTACK TEST");

	robotA.attack("Beta");
	robotB.takeDamage(0); // Damage is 0 by default
	robotB.attack("Alpha");

	printDivider("SET DAMAGE AND ATTACK");

	// Manually increase Alpha's attack damage
	std::cout << "Setting Alpha's attack damage to 5\n";
	// Hacky way since no setter – simulate by repeatedly attacking
	for (int i = 0; i < 3; i++) {
		robotA.attack("Beta");
		robotB.takeDamage(5); // simulate upgraded damage manually
	}

	printDivider("REPAIR TEST");

	robotB.beRepaired(3);

	printDivider("ZERO ENERGY TEST");

	ClapTrap tiredBot("Sleepy");
	for (int i = 0; i < 11; i++) {
		tiredBot.attack("Air");
	}

	printDivider("ZERO HIT POINT TEST");

	ClapTrap dyingBot("Doomed");
	dyingBot.takeDamage(10); // Now at 0 HP
	dyingBot.attack("Someone"); // Should do nothing
	dyingBot.beRepaired(5);     // Should do nothing

	printDivider("MIXED COMBAT SCENARIO");

	ClapTrap warrior("Thor");
	ClapTrap enemy("Loki");

	warrior.attack("Loki");
	enemy.takeDamage(0); // Still 0 attack damage
	enemy.beRepaired(2);
	for (int i = 0; i < 5; i++) {
		warrior.attack("Loki");
		enemy.takeDamage(2); // simulate increase in damage
		enemy.attack("Thor");
		warrior.takeDamage(1);
	}

	printDivider("DESTRUCTION TEST");

	return 0;
}
