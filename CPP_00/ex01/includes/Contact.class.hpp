#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class Contact
{
private:
    size_t      _index;
    std::string _first_name;
    std::string _last_name;
    std::string _nick_name;
    std::string _phone_nb;
    std::string _secret;
    
public:
    void    displayContact(size_t n);
    void    addContact(size_t current_size);
    void    setIndex(size_t index);
};

#endif