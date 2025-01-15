/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:05:38 by welow             #+#    #+#             */
/*   Updated: 2025/01/15 21:24:46 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define RESET "\e[0m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"
#define RED	"\e[31m"

bool bsp( Point const a, Point const b, Point const c, Point const p );

void	printIsPointInsideTriangle(Point const a, Point const b, Point const c, Point const p, bool expected )
{
	std::cerr << YELLOW "-- Triangle: A(" << a.getX() << ", " << a.getY() << ") "
		<< "| B(" << b.getX() << ", " << b.getY() << ") "
		<< "| C(" << c.getX() << ", " << c.getY() << ")" << std::endl
		<< "-- Point: P(" << p.getX() << ", " << p.getY() << ")" RESET << std::endl;
	std::cout << "point P inside triangle? ";
	if (bsp(a, b, c, p) == true)
		std::cout << GREEN "YES" RESET;
	else
		std::cout << RED "NO" RESET;
	std::cout << " (Expected: ";
	if (expected == true)
		std::cout << GREEN "YES" RESET;
	else
		std::cout << RED "NO" RESET;
	std::cout << ")" << std::endl << std::endl;
}

int	main( void )
{
	bool		expect;
	Point const a(0, 0);
	Point const b(6, 0);
	Point const c(0, 6);

	std::cout << std::endl << "-----Test-----" << std::endl << std::endl;
	{
		Point const p;
		expect = false;
		printIsPointInsideTriangle(a, b, c, p, expect);
	}
	{
		Point const p(a);
		expect = false;
		printIsPointInsideTriangle(a, b, c, p, expect);
	}
	{
		Point const p(10.0f, 1.5f);
		expect = false;
		printIsPointInsideTriangle(a, b, c, p, expect);
	}
	{
		Point const p(4.5f, 0.5f);
		expect = true;
		printIsPointInsideTriangle(a, b, c, p, expect);
	}
	return ( 0 );
}