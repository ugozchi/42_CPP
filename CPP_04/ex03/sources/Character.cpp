#include "Character.hpp"

/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                         Constructors / Destructor                         |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/

Character::Character() : _name( "no_one" ) {
	for (size_t i = 0; i < MAX_INVENTORY; i++)
		_inventory[i] = NULL;
}

Character::Character( std::string name ) : _name( name ) {
	for (size_t i = 0; i < MAX_INVENTORY; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& src) {
	_name = src._name;
	for (size_t i = 0; i < MAX_INVENTORY; i++) {
		if (_inventory[i])
			delete _inventory[i];
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character::~Character() {
	for (size_t i = 0; i < MAX_INVENTORY; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}


/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                          Assignment Operator                              |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/

Character& Character::operator=(const Character& src) {
	if (this != &src) {
		_name = src._name;
		for (size_t i = 0; i < MAX_INVENTORY; i++) {
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


/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                          Equiment Functions                               |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/

const std::string&      Character::getName() const { return (_name); }

void                    Character::equip(AMateria* m) {
	size_t	i = 0;

	while (i < MAX_INVENTORY && _inventory[i])
		i++;

	if (i < MAX_INVENTORY) {
		_inventory[i] = m;
		std::cout << "Equiping " << _name << " with " << m->getType();
		std::cout << " at index " << i << std::endl;
	}
}

void                    Character::unequip(int index) {
	if (index < MAX_INVENTORY && _inventory[index]) {
		_inventory[index] = NULL;
		std::cout << "Unequiping " << _name << std::endl;
	}
	else if (index >= MAX_INVENTORY)
		std::cout << index << " is not a valid index";
	else
		std::cout << "No equipment at index " << index << " for " << _name << std::endl; 
}

void                    Character::use(int index, ICharacter& target) {
	if (index < MAX_INVENTORY && _inventory[index]) {
		_inventory[index]->use(target);
	}
	else if (index >= MAX_INVENTORY)
		std::cout << index << " is not a valid index";
	else
		std::cout << "No equipment at index " << index << " for " << _name << std::endl; 
}