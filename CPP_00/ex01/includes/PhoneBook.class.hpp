#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include "Contact.class.hpp"

class PhoneBook {
    private:
    Contact contacts[8];
    size_t  current_size;
    void    deleteContact(void);

    public:
    PhoneBook(void);
    ~PhoneBook(void);

    void    addContact(void);
    void    searchContact(void);
};

#endif