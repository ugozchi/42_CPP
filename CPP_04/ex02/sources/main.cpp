#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define ARRAY_SIZE 4

void printDivider(const std::string& title) {
	std::cout << "\n===== " << title << " =====\n" << std::endl;
}

int main() {
	printDivider("ANIMAL ARRAY TEST");

	Animal* animals[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; ++i) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < ARRAY_SIZE; ++i)
		animals[i]->makeSound(); // polymorphic call

	for (int i = 0; i < ARRAY_SIZE; ++i)
		delete animals[i]; // calls virtual destructors

	printDivider("DEEP COPY TEST");

	Dog dog1;
	Dog dog2 = dog1; // Deep copy

	printDivider("DONE");

	// ❌ Ceci ne doit pas être autorisé (classe abstraite)
	// Animal a;            // <- Erreur de compilation
	// Animal* invalid = new Animal(); // <- Erreur aussi

	return 0;
}