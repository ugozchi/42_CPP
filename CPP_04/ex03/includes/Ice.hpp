#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice( const Ice& src );
	Ice& operator=( const Ice& src );
	~Ice();

    AMateria*   clone() const override;
    void        use(ICharacter& target) override;

};

#endif