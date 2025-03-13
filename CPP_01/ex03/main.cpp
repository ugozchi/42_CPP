#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>
#include <thread>
#include <chrono> 

// int main( void )
// {
// 	{
// 		Weapon club = Weapon("crude spiked club");

// 		HumanA bob("Bob", club);
// 		bob.attack();
// 		club.setType("some other type of club");
// 		bob.attack();
// 	}
// 	std::cout << std::endl;
// 	{
// 		Weapon club = Weapon("crude spiked club");
        
// 		HumanB jim("Jim");
// 		jim.setWeapon(club);
// 		jim.attack();
// 		club.setType("some other type of club");
// 		jim.attack();
// 	}
// 	return 0;
// }

void dramaticPause(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main() {
    std::cout << "⚔️  BATTLE BEGINS ⚔️\n" << std::endl;
    
    {
        std::cout << "🏋️‍♂️ Bob (HumanA) picks up a club..." << std::endl;
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        dramaticPause(1000);
        bob.attack();

        std::cout << "🛠️ Bob upgrades his weapon..." << std::endl;
        club.setType("reinforced steel club");
        dramaticPause(1000);
        bob.attack();
    }
    
    std::cout << "\n--------------------------------------\n" << std::endl;

    {
        std::cout << "🤷 Jim (HumanB) arrives unarmed..." << std::endl;
        Weapon sword = Weapon("rusty sword");

        HumanB jim("Jim");
        dramaticPause(1000);
        jim.attack(); // Jim has no weapon initially

        std::cout << "⚔️ Jim finds a sword and equips it!" << std::endl;
        jim.setWeapon(sword);
        dramaticPause(1000);
        jim.attack();

        std::cout << "🛠️ Jim sharpens his sword..." << std::endl;
        sword.setType("sharpened legendary sword");
        dramaticPause(1000);
        jim.attack();
    }

    std::cout << "\n--------------------------------------\n" << std::endl;

    {
        std::cout << "💪 Alice (HumanA) enters the arena with a spear..." << std::endl;
        Weapon spear = Weapon("wooden spear");

        HumanA alice("Alice", spear);
        dramaticPause(1000);
        alice.attack();

        std::cout << "🔧 Alice upgrades her spear to a steel version..." << std::endl;
        spear.setType("steel-tipped spear");
        dramaticPause(1000);
        alice.attack();
    }

    std::cout << "\n--------------------------------------\n" << std::endl;

    {
        std::cout << "🤠 Jack (HumanB) joins the fight unarmed..." << std::endl;
        Weapon dagger = Weapon("small dagger");

        HumanB jack("Jack");
        dramaticPause(1000);
        jack.attack(); // Jack starts without a weapon

        std::cout << "🗡️ Jack finds a dagger and picks it up!" << std::endl;
        jack.setWeapon(dagger);
        dramaticPause(1000);
        jack.attack();

        std::cout << "🔥 Jack sets his dagger on fire!" << std::endl;
        dagger.setType("flaming dagger");
        dramaticPause(1000);
        jack.attack();
    }

    std::cout << "\n🏆 BATTLE ENDED! All warriors have tested their weapons. 🏆" << std::endl;
    return 0;
}
