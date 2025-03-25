#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "Character.hpp"
class ICharacter;

class AMateria
{
protected:
    std::string     _type;

public:
    AMateria( void );
    AMateria( std::string const & type );
    AMateria( const AMateria& src );
    AMateria&   operator=( const AMateria& src );
    virtual ~AMateria();

    const std::string&  getType( void ) const;

    virtual AMateria*   clone() const = 0;
    virtual void        use(ICharacter& target);
};

#endif