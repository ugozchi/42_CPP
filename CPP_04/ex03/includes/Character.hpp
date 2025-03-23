#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class ICharacter
{
public:
	virtual 					~ICharacter() {};
	virtual const std::string&	getName() const = 0;
	virtual void				equip(AMateria* m) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void				use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
private:
	std::string		_name;
	static const int MAX_INVENTORY = 4;
	AMateria*		_inventory[MAX_INVENTORY];

public:
	Character();
	Character( std::string name );
	Character( const Character& src );
	Character&	operator=( const Character& src );
	~Character();

	const std::string&	getName() const override;
	void				equip(AMateria* m) override;
	void				unequip(int idx) override;
	void				use(int idx, ICharacter& target) override;
};

#endif