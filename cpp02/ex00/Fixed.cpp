/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:16:48 by welow             #+#    #+#             */
/*   Updated: 2025/02/19 17:33:52 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"



Fixed::Fixed() : _fixed_point_nb(0)
{
	std::cout << BLUE_H << "Default constructor called" << RESET << std::endl;
}

/**
 * @brief copy constructor
 * @param src source to copy
 * @note "*this" is a pointer to the object itself
*/
Fixed::Fixed(const Fixed &src)
{
	std::cout << RED_H << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

/**
 * @brief assignment operator
 * @param src source to copy
 * @note if the source is not same, copy the source to this object
 * @return *this
*/
Fixed &Fixed::operator=( Fixed const &src)
{
	std::cout << YELLOW_H << "Copy assignment operator called" << RESET << std::endl;
	this->_fixed_point_nb = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << GREEN_H << "Destructor called" << RESET << std::endl;
}

void	Fixed::setRawBits( int const fixed_point_nb )
{
	this->_fixed_point_nb = fixed_point_nb;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << PURPLE_H << "getRawBits member function called" << RESET << std::endl;
	return this->_fixed_point_nb;
}

