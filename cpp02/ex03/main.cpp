/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:05:38 by welow             #+#    #+#             */
/*   Updated: 2025/02/20 21:30:31 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const p );

void	printIsPointInsideTriangle(Point const a, Point const b, Point const c, Point const p)
{
	std::cout << CYAN << "-- Triangle: A(" << a.getX() << ", " << a.getY() << ") "
		<< "| B(" << b.getX() << ", " << b.getY() << ") "
		<< "| C(" << c.getX() << ", " << c.getY() << ")" << std::endl
		<< "-- Point   : P(" << p.getX() << ", " << p.getY() << ")" << RESET << std::endl;
	if (bsp(a, b, c, p) == true)
		std::cout << "point P inside triangle: "<< GREEN "YES" RESET<< std::endl;
	else
		std::cout << "point P inside triangle: " << RED "NO" RESET << std::endl;
}

int	main( void )
{
	{
		Point	a(0, 0);
		Point	b(10, 30);
		Point	c(20, 0);
		Point	p(10, 15);
		printIsPointInsideTriangle(a, b, c, p);
	}
	{
		Point	a(0, 0);
		Point	b(5, 5);
		Point	c(0, 10);
		Point	p(2.5f, 2.5f);
		printIsPointInsideTriangle(a, b, c, p);
	}
	{
		Point	a(0, 0);
		Point	b(0, 0);
		Point	c(1, 1);
		Point	p(-1, 5);
		printIsPointInsideTriangle(a, b, c, p);
	}
	{
		Point	a(0, 0);
		Point	b(6, 0);
		Point	c(0, 6);
		Point	p(4.5f, 0.5f);
		printIsPointInsideTriangle(a, b, c, p);
	}
	return ( 0 );
}
