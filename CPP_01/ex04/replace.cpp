#include "replace.hpp"

static std::string	new_filename( std::string filename )
{
	size_t	last_dot = filename.rfind('.');

	if (last_dot != std::string::npos)
		return (filename.substr(0, last_dot) + ".replace");
	else
		return (filename + ".replace");
}

static std::string	replace_in_string( std::string str, std::string& search, std::string& replace )
{
	std::string::size_type	found = str.find(search);

	if (found == std::string::npos)
		return (str);

	std::string	before = str.substr(0, found);
	std::string	after = replace_in_string(str.substr(found + search.length()), search, replace);

	return (before + replace + after);
}

int	replace( std::ifstream& input_fs, char **av )
{
	std::ofstream	output_fs;
	std::string		filename = av[1];
	std::string		line;
	std::string		search = av[2];
	std::string		replace = av[3];

	output_fs.open(new_filename(filename).c_str(), std::fstream::out);
	if (!output_fs.is_open())
	{
		std::cout << "Error while opening the output file" << std::endl;
		return (EXIT_FAILURE);
	}
	while (getline(input_fs, line))
	{
		output_fs << replace_in_string(line, search, replace) << std::endl;
		if (!output_fs.good())
		{
			std::cout << "Error while writing the output file" << std::endl;
			return (EXIT_FAILURE);
		}
	}
	if (!input_fs.eof() && input_fs.fail())
	{
		std::cout << "Error while reading the input file" << std::endl;
		return (EXIT_FAILURE);
	}
	output_fs.close();
	return (EXIT_SUCCESS);
}