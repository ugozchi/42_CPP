#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
private:
    void    debug( void );
    void    info( void );
    void    warning( void );
    void    error( void );

public:
    Harl();
    ~Harl();

    void    complain( const std::string& level );
    void    (Harl::*getFunction( const std::string& level ))();
    int     getLevel( const std::string& level );
};

#endif