#include "Zombie.hpp"
#include <iostream>


int main() {
    std::cout << "💀 BIENVENUE DANS L'APOCALYPSE ZOMBIE 💀" << std::endl;
    std::cout << "Prépare-toi... La horde approche... 😱" << std::endl;

    int N = 5;
    std::cout << "\n🔥 Création d'une horde de " << N << " zombies... 🔥" << std::endl;
    
    Zombie* horde = zombieHorde(N, "Walker");

    std::cout << "\n⚠️  La horde se réveille... ⚠️" << std::endl;

    for (int i = 0; i < N; i++) {
        std::cout << "🧟‍♂️ Zombie #" << i + 1 << " : ";
        horde[i].announce();
    }

    std::cout << "\n🚨 L'armée est en route pour éliminer les zombies... 🚨" << std::endl;
    std::cout << "\n💥 BOOOOOM 💥 !!!" << std::endl;

    std::cout << "\n💀 Destruction de la horde... 💀" << std::endl;
    delete[] horde;

    std::cout << "\n✅ Apocalypse terminée. Les humains ont survécu ! ✅" << std::endl;
    return 0;
}