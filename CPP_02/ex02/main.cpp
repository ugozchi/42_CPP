#include <iostream>
#include "Fixed.hpp"

#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c;

	std::cout << std::endl << "\033[1;32mCOMPARISON OPERATORS" << std::endl;
	std::cout << "a is " << a << ", b is " << b << "\033[0m" << std::endl;

	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "b > a is " << (b > a) << std::endl;
	std::cout << "a > a is " << (a > a) << std::endl;
	std::cout << "a < b is " << (a < b) << std::endl;
	std::cout << "a < a is " << (a < a) << std::endl;
	std::cout << "a >= b is " << (a >= b) << std::endl;
	std::cout << "a >= a is " << (a >= a) << std::endl;
	std::cout << "a <= b is " << (a <= b) << std::endl;
	std::cout << "a <= a is " << (a <= a) << std::endl;
	std::cout << "a == b is " << (a == b) << std::endl;
	std::cout << "a == a is " << (a == a) << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl;
	std::cout << "a != a is " << (a != a) << std::endl << std::endl;

	std::cout << "\033[1;32mARITHMETIC OPERATORS" << std::endl;
	std::cout << "a is " << a << ", b is " << b << "\033[0m" << std::endl;
	
	std::cout << "a + b is " << (a + b) << std::endl;
	std::cout << "a - b is " << (a - b) << std::endl;
	std::cout << "a * b is " << (a * b) << std::endl;
	std::cout << "b * b is " << (b * b) << std::endl;
	std::cout << "a / b is " << (a / b) << std::endl;
	std::cout << "5 / b is " << (Fixed( 5 ) / b) << std::endl << std::endl;

	std::cout << "\033[1;32mINCREMENT / DECREMENT OPERATORS" << "\033[0m" << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "++a is " << ++a << std::endl;
	std::cout << "Now a is " << a << std::endl;
	std::cout << "a++ is " << a++ << std::endl;
	std::cout << "Now a is " << a << std::endl<<std::endl;

	std::cout << "\033[1;32mMIN / MAX STATICS" << std::endl;
	std::cout << "a is " << a << ", b is " << b << "\033[0m" << std::endl;

	std::cout << "Fixed::max( a, b ) is " << Fixed::max( a, b ) << std::endl;
	std::cout << "Fixed::min( a, b ) is " << Fixed::min( a, b ) << std::endl;


	return 0;
}