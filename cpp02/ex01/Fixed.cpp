/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:27:27 by welow             #+#    #+#             */
/*   Updated: 2025/01/06 19:58:28 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief convert the integer to fixed point
 * @param nb integer value to convert
 * @note 1. EXAMPLE : [ 10 << 8 ] => [ 10 * 2^8 ] => [ 10 * 256 = 2560 ]
*/
Fixed::Fixed( int const nb )
{
	std::cout << "Int constructor called"<< std::endl;
	this->_raw = nb << Fixed::_bit;
}

/**
 * @brief convert the float to fixed point
 * @param nb float value to convert
 * @note 1. EXAMPLE : [ roundf(42.42 * (1 << 8)) ] => [ roundf(42.42 * 2^8) ] => [ roundf(42.42 * 256) = 10837 ]
*/
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
	return this->_raw;
}

/**
 * @brief convert fixed point value to floating point value 
 * @return floating point value
*/
float	Fixed::toFloat( void ) const
{
	//1 << 8 = 256
	//std::cout << "toFloat member function called" << std::endl; //visualize
	//std::cout << (float)this->_raw  << "/" << (1 << Fixed::_bit) << " = "; //visualize
	return ((float)this->_raw / (1 << Fixed::_bit));
}

/**
 * @brief convert fixed point value to integer value
 * @return integer value
*/
int	Fixed::toInt( void ) const
{
	//std::cout << "toInt member function called" << std::endl; //visualize
	//std::cout << this->_raw << ">>" << Fixed::_bit << " = "; //visualize
	return this->_raw >> Fixed::_bit;
}

/**
 * @brief when "std::cout" is called, this function will be called to do other operation
 * @param output output stream
 * @param src copy of the value
 * @return output stream
 * @note it convert output to floating point value
*/
std::ostream	&operator<<(std::ostream &output, Fixed const &src)
{
	output << src.toFloat();
	return output;
}