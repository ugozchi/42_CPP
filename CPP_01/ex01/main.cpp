#include "Zombie.hpp"
#include <iostream>
#include <thread>   // Pour sleep
#include <chrono>   // Pour sleep

void dramaticPause(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main() {
    std::cout << "💀 BIENVENUE DANS L'APOCALYPSE ZOMBIE 💀" << std::endl;
    std::cout << "Prépare-toi... La horde approche... 😱" << std::endl;
    dramaticPause(2000);

    int N = 5;
    std::cout << "\n🔥 Création d'une horde de " << N << " zombies... 🔥" << std::endl;
    dramaticPause(1500);
    
    Zombie* horde = zombieHorde(N, "Walker");

    std::cout << "\n⚠️  La horde se réveille... ⚠️" << std::endl;
    dramaticPause(1000);

    for (int i = 0; i < N; i++) {
        std::cout << "🧟‍♂️ Zombie #" << i + 1 << " : ";
        horde[i].announce();
        dramaticPause(700);
    }

    std::cout << "\n🚨 L'armée est en route pour éliminer les zombies... 🚨" << std::endl;
    dramaticPause(2000);
    std::cout << "\n💥 BOOOOOM 💥 !!!" << std::endl;
    dramaticPause(1000);

    std::cout << "\n💀 Destruction de la horde... 💀" << std::endl;
    delete[] horde;
    dramaticPause(1500);

    std::cout << "\n✅ Apocalypse terminée. Les humains ont survécu ! ✅" << std::endl;
    return 0;
}