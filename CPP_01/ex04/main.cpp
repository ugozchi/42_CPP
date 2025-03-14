#include "replace.hpp"

int	main( int ac, char **av )
{
	std::ifstream	input_fs;
	int				exit_code;

	if (ac != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	input_fs.open(av[1], std::fstream::in);
	if (!input_fs.is_open())
	{
		std::cout << "Error while opening the input file" << std::endl;
		return (EXIT_FAILURE);
	}
	exit_code = replace(input_fs, av);
	input_fs.close();
	return (exit_code);
}
