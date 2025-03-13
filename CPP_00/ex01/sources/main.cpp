# include "main.hpp"
# include "PhoneBook.class.hpp"
# include <limits>

int main()
{
    PhoneBook   pb;
    std::string input;

    while (1)
    {
        std::cout << "PhoneBook > ";
        std::getline(std::cin, input);
        if (input == "EXIT" || std::cin.eof())
            break ;
        else if (input.empty())
            continue ;
        else if (input == "ADD") {
            pb.addContact();
        }
        else if (input == "SEARCH") {
            pb.searchContact();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            std::cout << "⚠️ Invalid option ⚠️" << std::endl << std::endl;
    }
}