/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:16:48 by welow             #+#    #+#             */
/*   Updated: 2024/12/27 19:29:05 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief copy constructor
 * @param src source to copy
 * @note "*this" is a pointer to the object itself
*/
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
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
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
		this->_raw = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits( int const raw )
{
	this->_raw = raw;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "" << endl;
	return this->raw;
}

