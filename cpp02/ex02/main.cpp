/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:49:29 by welow             #+#    #+#             */
/*   Updated: 2025/01/13 15:18:14 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	{
		std::cout << "----------test 1----------" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	{
		std::cout << std::endl << "----------comparison operator----------" << std::endl;
		Fixed a(20);
		Fixed b(10);

		bool res = a > b;
		if (res == 0)
			std::cout << "a is not greater than b" << std::endl;
		else
			std::cout << "a is greater than b" << std::endl;

		res = a >= b;
		if (res == 0)
			std::cout << "a is not greater or equal to b" << std::endl;
		else
			std::cout << "a is greater or equal to b" << std::endl;

		res = a == b;
		if (res == 0)
			std::cout << "a is not equal to b" << std::endl;
		else
			std::cout << "a is equal to b" << std::endl;

	}

	{
		std::cout << std::endl << "----------arithmetic operator----------" << std::endl;
		Fixed a(20);
		Fixed b(10);

		Fixed c = a + b;
		std::cout << a << " + " << b << " = " << c << std::endl;

		c = a - b;
		std::cout << a << " - " << b << " = " << c << std::endl;

		c = a * b;
		std::cout << a << " * " << b << " = " << c << std::endl;

		c = a / b;
		std::cout << a << " / " << b << " = " << c << std::endl;
	}

	{
		std::cout << std::endl << "----------min/max operator----------" << std::endl;
		Fixed a(20);
		Fixed b(10);

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		Fixed c = Fixed::min(a, b);
		std::cout << "min(a, b) = " << c << std::endl;

		c = Fixed::max(a, b);
		std::cout << "max(a, b) = " << c << std::endl;
	}

	{
		std::cout << std::endl << "----------increament/decreament operator----------" << std::endl;
		Fixed a(20); //this will convert to fixed point 20.0

		std::cout << "ori a: " << a << std::endl;
		a++;
		std::cout << "increament a: " << a << std::endl;
		a--;
		std::cout << "decreament a: " << a << std::endl;
	}
	return 0;
}