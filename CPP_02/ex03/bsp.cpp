#include "Point.hpp"

bool	same_sign(Fixed m, Fixed n)
{
	return ((m > 0 && n > 0) || (m < 0 && n < 0));
}

bool	same_half_plan(Point const a, Point const b, Point const m, Point const n)
{
	Fixed	A = b.getY() - a.getY();
	Fixed	B = a.getX() - b.getX();
	Fixed	C = Fixed(-1) * (A * a.getX() + B * a.getY());

	Fixed value1 = A * m.getX() + B * m.getY() + C;
	Fixed value2 = A * n.getX() + B * n.getY() + C;

	if (value1 == 0 || value2 == 0)
		return (false);

	bool	sign1 = same_sign(value1, Fixed( 1 ));
	bool	sign2 = same_sign(value2, Fixed( 1 ));

	if ((sign1 && sign2) || (!sign1 && !sign2))
		return (true);
	else
		return (false);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	return (same_half_plan(a, b, c, point) &&
			same_half_plan(b, c, a, point) &&
			same_half_plan(a, c, b, point));
}