#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
protected:
    std::string         _name;
    unsigned int        _hitPoints;
    unsigned int        _energy;
    unsigned int        _damage;

public:
    /*Constructors and Destructor*/
    ClapTrap();
    ClapTrap( std::string name );
    ClapTrap( const ClapTrap& src );
    ~ClapTrap();

    /*Assignment Operator*/
    ClapTrap&   operator=( const ClapTrap& src );

    /*Insances attribut*/
    std::string		getName( void ) const;
	unsigned int	getHitPoints( void ) const;
	unsigned int	getEnergyPoints( void ) const;
	unsigned int	getAttackDamage( void ) const;

    /*Action functions*/
    void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
};

#endif