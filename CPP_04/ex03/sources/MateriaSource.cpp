#include "MateriaSource.hpp"
#include <iostream>

/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                         Constructors / Destructor                         |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/

MateriaSource::MateriaSource() {
	for (int i = 0; i < MAX_INVENTORY; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
	if (this != &src) {
		for (int i = 0; i < MAX_INVENTORY; i++) {
			if (_inventory[i])
				delete _inventory[i];
			if (src._inventory[i])
				_inventory[i] = src._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}


/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                             Materia Functions                             |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/

void MateriaSource::learnMateria(AMateria* src) {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (!_inventory[i]) {
			_inventory[i] = src;
			std::cout << src->getType() << " type has been learned" << std::endl;
			return;
		}
	}
	std::cout << "Inventory full, cannot learn more materias" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (_inventory[i] && _inventory[i]->getType() == type) {
			std::cout << "Creating " << type << std::endl;
			return (_inventory[i]->clone());
		}
	}
	std::cout << "Cannot create materia " << type << ", type unknown" << std::endl;
	return NULL;
}
