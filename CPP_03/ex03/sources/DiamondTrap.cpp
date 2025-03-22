#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap() {
	_name = "no_name";
	ClapTrap::_name = _name + "_clap_name";

	this->_hitPoints = FragTrap::_hitPoints;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;

	std::cout << "DiamondTrap default constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name ), ScavTrap( name ), FragTrap( name ) {
	_name = name;
	ClapTrap::_name = name + "_clap_name";

	this->_hitPoints = FragTrap::_hitPoints;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;

	std::cout << "DiamondTrap constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& src ) : ScavTrap( src ), FragTrap( src ) {
	_name = src._name;
	std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& src ) {
	if (this != &src)
	{
		_name = src._name;
		ClapTrap::_name = src.ClapTrap::_name;
		_hitPoints = src._hitPoints;
		_energy = src._energy;
		_damage = src._damage;
	}
	std::cout << "DiamondTrap assignment operator used for " << _name << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap default destructor called for " << _name << std::endl;
}

void	DiamondTrap::whoAmI( void ) {
	std::cout << "I am a DiamondTrap with two names: " << _name;
	std::cout << " and " << ClapTrap::_name << std::endl;
}