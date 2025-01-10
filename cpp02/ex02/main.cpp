/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:49:29 by welow             #+#    #+#             */
/*   Updated: 2025/01/10 15:27:32 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a; //create default constructor

	//create float constructor(create float constructor, create int constructor)
	//after multiple then destroy the int constructor and float constructor
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "original a" << std::endl;
	std::cout << a << std::endl;

	std::cout << std::endl;

	std::cout << "pre-increament" << std::endl;
	std::cout << ++a << std::endl; //increament operator -> output operator
	std::cout << a << std::endl;

	std::cout << std::endl;

	std::cout << "post-increament" << std::endl;
	std::cout << a++ << std::endl; //increament operator -> output operator
	std::cout << a << std::endl;

	std::cout << std::endl;

	std::cout << "original b" << std::endl;
	std::cout << b << std::endl;

	std::cout <<std::endl;

	std::cout << "get biggest"<< std::endl;
	std::cout << Fixed::max( a, b ) << std::endl; //compare operator -> output operator

	std::cout << "get smallest"<< std::endl;
	std::cout << Fixed::min( a, b ) << std::endl; //compare operator -> output operator


	return 0;
}