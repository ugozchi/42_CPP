# include <iostream>
# include <cctype>

int main(int ac, char *av[])
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < ac; i++)
        {
            std::string str = av[i];
            for (std::size_t j = 0; j < str.length(); j++)
                str[j] = std::toupper(str[j]);

            std::cout << str;
            if (i < ac - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}