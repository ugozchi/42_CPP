# include "main.hpp"
# include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
    current_size = 0;
    std::cout << "Welcome on Nokia 3310 📞\n" << std::endl;
    std::cout << "Options :\n- ADD\n- SEARCH\n- EXIT\n" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << std::endl << "Bliiip ! 🎵" << std::endl;
}

void    PhoneBook::addContact(void)
{
    if (current_size == 8)
        deleteContact();
	contacts[current_size].addContact(current_size);
    if (current_size < 8)
        current_size++;
}

static bool  indexValidation(std::string input, int current_size)
{
    if (input.length() > 1)
        return (false);
    if (!isdigit(input[0]))
        return (false);
    if (input[0] - '0' < 0 || input[0] - '0' > (int)current_size - 1)
        return (false);
    return (true);
}

void    PhoneBook::searchContact(void)
{
    std::string search_index;

    if (!current_size)
        std::cout << "Phonebook empty ⦰" << std::endl;
    else {
        std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
        for (size_t i = 0; i < this->current_size; i++)
            contacts[i].displayContact(1);
        std::cout << std::endl << "Enter an index :";
        std::cin >> search_index;
        if (!indexValidation(search_index, (int)current_size))
            std::cout << search_index << std::endl << "It's not a correct index" << std::endl;
        else
            contacts[search_index[0] - '0'].displayContact(2);
    }
}

void    PhoneBook::deleteContact(void)
{
    for (size_t i = 0; i < 7; i++)
    {
        contacts[i] = contacts[i + 1];
        contacts[i].setIndex(i);
    }
    current_size--;
}