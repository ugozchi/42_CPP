#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "FragTrap default constructor called for " << _name << std::endl;
	_hitPoints = 100;
	_energy = 100;
	_damage = 30;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {
	std::cout << "FragTrap constructor called for " << _name << std::endl;
	_hitPoints = 100;
	_energy = 100;
	_damage = 30;
}

FragTrap::FragTrap( const FragTrap& src ) : ClapTrap( src ) {
	std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& src ) {
	if (this != &src)
	{
		static_cast<ClapTrap&>(*this) = src;
		std::cout << "FragTrap assignment operator used for " << _name << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap default destructor called for " << _name << std::endl;
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << "Positive high five request for " << _name << std::endl;
}