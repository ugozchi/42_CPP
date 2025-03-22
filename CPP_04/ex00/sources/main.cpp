#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include <iostream>

void printDivider(const std::string& label) {
	std::cout << "\n===== " << label << " =====\n" << std::endl;
}

int main() {
	printDivider("CORRECT POLYMORPHISM TESTS");

	const Animal* a = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();

	std::cout << d->getType() << " makes sound: ";
	d->makeSound();

	std::cout << c->getType() << " makes sound: ";
	c->makeSound();

	std::cout << a->getType() << " makes sound: ";
	a->makeSound();

	delete a;
	delete d;
	delete c;

	printDivider("BROKEN POLYMORPHISM TESTS");

	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	const WrongAnimal* wd = new WrongDog();

	std::cout << wc->getType() << " makes sound: ";
	wc->makeSound(); // ❌ calls WrongAnimal::makeSound()

	std::cout << wd->getType() << " makes sound: ";
	wd->makeSound(); // ❌ calls WrongAnimal::makeSound()

	std::cout << wa->getType() << " makes sound: ";
	wa->makeSound(); // ✅ WrongAnimal::makeSound()

	delete wa;
	delete wc;
	delete wd;

	printDivider("DIRECT CALLS ON WRONG CLASSES");

	WrongCat directWC;
	WrongDog directWD;

	std::cout << directWC.getType() << " makes sound: ";
	directWC.makeSound(); // ✅ Meow

	std::cout << directWD.getType() << " makes sound: ";
	directWD.makeSound(); // ✅ Bark

	printDivider("DONE");
	return 0;
}
