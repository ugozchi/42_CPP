#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *ptr = &str;
    std::string &ref = str;

    std::cout << &str << std::endl << ptr << std::endl << &ref << std::endl << std::endl;
    std::cout << str << std::endl << *ptr << std::endl << ref << std::endl << std::endl;
}