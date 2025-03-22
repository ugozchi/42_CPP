#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define ARRAY_SIZE 4

void printDivider(const std::string& title) {
	std::cout << "\n===== " << title << " =====\n" << std::endl;
}

int main() {
	printDivider("ANIMAL ARRAY CONSTRUCTION");

	Animal* animals[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; ++i) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	printDivider("ANIMAL ARRAY DESTRUCTION");

	for (int i = 0; i < ARRAY_SIZE; ++i) {
		delete animals[i];
	}

	printDivider("DEEP COPY TEST");

	Dog original;
	Dog copy(original);

	printDivider("DEEP COPY TEST FINISHED");

	return 0;
}
