#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main( void ) {
    std::cout << "⚔️  BATTLE BEGINS ⚔️\n" << std::endl;
    
    {
        std::cout << "🏋️‍♂️ Bob (HumanA) picks up a club..." << std::endl;
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        bob.attack();

        std::cout << "🛠️ Bob upgrades his weapon..." << std::endl;
        club.setType("reinforced steel club");
        bob.attack();
    }
    
    std::cout << "\n--------------------------------------\n" << std::endl;

    {
        std::cout << "🤷 Jim (HumanB) arrives unarmed..." << std::endl;
        Weapon sword = Weapon("rusty sword");

        HumanB jim("Jim");
        jim.attack(); // Jim has no weapon initially

        std::cout << "⚔️ Jim finds a sword and equips it!" << std::endl;
        jim.setWeapon(sword);
        jim.attack();

        std::cout << "🛠️ Jim sharpens his sword..." << std::endl;
        sword.setType("sharpened legendary sword");
        jim.attack();
    }

    std::cout << "\n--------------------------------------\n" << std::endl;

    {
        std::cout << "💪 Alice (HumanA) enters the arena with a spear..." << std::endl;
        Weapon spear = Weapon("wooden spear");

        HumanA alice("Alice", spear);
        alice.attack();

        std::cout << "🔧 Alice upgrades her spear to a steel version..." << std::endl;
        spear.setType("steel-tipped spear");
        alice.attack();
    }

    std::cout << "\n--------------------------------------\n" << std::endl;

    {
        std::cout << "🤠 Jack (HumanB) joins the fight unarmed..." << std::endl;
        Weapon dagger = Weapon("small dagger");

        HumanB jack("Jack");
        jack.attack(); // Jack starts without a weapon

        std::cout << "🗡️ Jack finds a dagger and picks it up!" << std::endl;
        jack.setWeapon(dagger);
        jack.attack();

        std::cout << "🔥 Jack sets his dagger on fire!" << std::endl;
        dagger.setType("flaming dagger");
        jack.attack();
    }

    std::cout << "\n🏆 BATTLE ENDED! All warriors have tested their weapons. 🏆" << std::endl;
    return 0;
}
