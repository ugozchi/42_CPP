#include "Point.hpp"
#include <iostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int main( void )
{
	Point const a(2, 5);
	Point const b(6, 3);
	Point const c(4, 7);

	std::cout << "TRIANGLE BETWEEN (0,0), (6,0) and (3,6)" << std::endl << std::endl;

	std::cout << "TEST 1: (3,5) - inside" << std::endl;
	std::cout << "Algo outputs " << (bsp(a, b, c, Point(3, 5)) ? "true" : "false") << ", true expected" << std::endl << std::endl;

	std::cout << "TEST 2: (8,6) - outside" << std::endl;
	std::cout << "Algo outputs " << (bsp(a, b, c, Point(8, 6)) ? "true" : "false") << ", false expected" << std::endl << std::endl;

	std::cout << "TEST 3: (4, 4) - on edge" << std::endl;
	std::cout << "Algo outputs " << (bsp(a, b, c, Point(4, 4)) ? "true" : "false") << ", false expected" << std::endl << std::endl;

	std::cout << "TEST 4: (6, 0) - on vertex" << std::endl;
	std::cout << "Algo outputs " << (bsp(a, b, c, Point(6, 0)) ? "true" : "false") << ", false expected" << std::endl << std::endl;

	return (0);
}