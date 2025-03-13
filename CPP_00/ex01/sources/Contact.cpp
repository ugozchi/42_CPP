# include <iostream>
# include <iomanip>
# include "Contact.class.hpp"

void    Contact::addContact(size_t current_size)
{
    std::string         labels[] = {"First name", "Last name", "Nickname", "Phone number", "Darkest Secret"};
    std::string*  attributes[] = {&_first_name, &_last_name, &_nick_name, &_phone_nb, &_secret};

    this->_index = current_size;
    for (size_t i = 0; i < 5; i++)
    {
        do
        {
            std::cout << labels[i] << ": ";
            if (!std::getline(std::cin, *attributes[i]) || std::cin.eof())
                break ;
        } while (attributes[i]->empty());
    }
    std::cout << std::endl;
}

void    Contact::setIndex(size_t index)
{
    _index = index;
}

void    displayTruncate(const std::string& str)
{
    if (str.length() > 10)
        std::cout << std::setw(10) << str.substr(0,9) + ".";
    else
        std::cout << std::setw(10) << str;
}

void    Contact::displayContact(size_t n) 
{
    std::string         labels[] = {"First name", "Last name", "Nickname", "Phone number", "Darkest Secret"};
    const std::string*  attributes[] = {&_first_name, &_last_name, &_nick_name, &_phone_nb, &_secret};
    
    if (n == 1) {
        std::cout << std::setw(10) << _index;
        std::cout << "|";
        displayTruncate(_first_name);
        std::cout << "|";
        displayTruncate(_last_name);
        std::cout << "|";
        displayTruncate(_nick_name);
        std::cout << std::endl;
    }
    else if (n == 2) {
        for (size_t i = 0; i < 5; i++)
            std::cout << labels[i] << ": " << *attributes[i] << std::endl;
    }
    else
        std::cout << "Error 404" << std::endl;
}
