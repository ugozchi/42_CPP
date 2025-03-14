#include "Harl.hpp"

int main( int ac, char **av )
{
    if (ac != 2)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        std::cerr << "Only one argument are expected" << std::endl;
        std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		return (EXIT_FAILURE);
    }
    
    Harl            harl;
    int             index = harl.getLevel(av[1]);

    if (index == -1) {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (EXIT_FAILURE);
    }

    switch (index) {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
    }
    
    return (EXIT_SUCCESS);
}