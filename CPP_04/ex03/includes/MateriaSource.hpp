#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
    
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
private:
	static const int MAX_INVENTORY = 4;
	AMateria*		_inventory[MAX_INVENTORY];
    // size_t		_index;

public:
    MateriaSource();
    MateriaSource( const MateriaSource& src );
    MateriaSource&  operator=( const MateriaSource& src );
    ~MateriaSource();

    void        learnMateria(AMateria*);
    AMateria*	createMateria(std::string const & type);
};



#endif