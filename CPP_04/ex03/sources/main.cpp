#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
	std::cout << "\n===== MATERIA SOURCE TEST =====\n" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\n===== CHARACTER CREATION =====\n" << std::endl;

	ICharacter* me = new Character("Player");
	std::cout << "Character created: " << me->getName() << std::endl;

	std::cout << "\n===== CREATING & EQUIPPING MATERIAS =====\n" << std::endl;

	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

    tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
    me->equip(tmp);

    tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

    me->unequip(2);
    me->equip(tmp);

	tmp = src->createMateria("unknown"); // Doit échouer

	std::cout << "\n===== TARGET CHARACTER =====\n" << std::endl;

	ICharacter* bob = new Character("Bob");
	std::cout << "Target created: " << bob->getName() << std::endl;
	
	std::cout << "\n===== USING MATERIAS =====\n" << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob); // Slot vide
	me->use(42, *bob); // invalid index

	std::cout << "\n\n===== DEEP COPY TEST =====\n" << std::endl;

	ICharacter* clone = new Character(*(Character*)me);
	clone->use(0, *bob);
	clone->use(1, *bob);

	std::cout << "\n===== CLEANUP =====\n" << std::endl;

	delete bob;
	delete me;
	delete clone;
	delete src;

	return 0;
}