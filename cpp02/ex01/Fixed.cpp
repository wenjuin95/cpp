/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:27:27 by welow             #+#    #+#             */
/*   Updated: 2025/01/02 18:44:40 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const nb )
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw = nb << Fixed::_bit;
}

Fixed::Fixed( float const nb )
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(nb * (1 << Fixed::_bit));
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
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_raw = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * @brief set the raw value
 * @param raw raw value to set
*/
void	Fixed::setRawBits( int const raw )
{
	this->_raw = raw;
}

/**
 * @brief get the raw value
 * @return raw value
*/
int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

/**
 * @brief convert the fixed point value to float
 * @return float value of the fixed point value
*/
float	Fixed::toFloat( void ) const
{
	//1 << 8 = 256
	return ((float)this->_raw / (1 << Fixed::_bit));
}

/**
 * @brief convert the fixed point value to int
 * @return integer value of the fixed point value
*/
int	Fixed::toInt( void ) const
{
	return this->_raw >> Fixed::_bit;
}

/**
 * @brief output the fixed point value to the output stream
 * @param output output stream
 * @param src copy of the fixed point value
 * @return output stream
 * @note output the float value of the fixed point value
*/
std::ostream	&operator<<(std::ostream &output, Fixed const &src)
{
	output << src.toFloat();
	return output;
}