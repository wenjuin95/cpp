/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:27:27 by welow             #+#    #+#             */
/*   Updated: 2025/02/19 17:37:24 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_nb(0)
{
	std::cout << BLUE_H << "Default constructor called" << RESET << std::endl;
}

/**
 * @brief convert the integer to fixed point
 * @param nb integer value to convert
 * @note 1. EXAMPLE : [ 10 << 8 ] => [ 10 * 2^8 ] => [ 10 * 256 = 2560 ]
*/
Fixed::Fixed( int const nb )
{
	std::cout << "Int constructor called"<< std::endl;
	this->_fixed_point_nb = nb << Fixed::_fractional_bit;
}

/**
 * @brief convert the float to fixed point
 * @param nb float value to convert
 * @note 1. EXAMPLE : [ roundf(42.42 * (1 << 8)) ] => [ roundf(42.42 * 2^8) ] => [ roundf(42.42 * 256) = 10837 ]
*/
Fixed::Fixed( float const nb )
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_nb = roundf(nb * (1 << Fixed::_fractional_bit));
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
	std::cout << GREEN_H << "Destructor called" << RESET << std::endl;;
}

/**
 * @brief set the raw value
 * @param raw raw value to set
*/
void	Fixed::setRawBits( int const raw )
{
	this->_fixed_point_nb = raw;
}

/**
 * @brief get the raw value
 * @return raw value
*/
int	Fixed::getRawBits( void ) const
{
	return this->_fixed_point_nb;
}

/**
 * @brief convert fixed point value to floating point value
 * @return floating point value
*/
float	Fixed::toFloat( void ) const
{
	//1 << 8 = 256
	//std::cout << "toFloat member function called" << std::endl; //visualize
	//std::cout << (float)this->_fixed_point_nb  << "/" << (1 << Fixed::_fractional_bit) << " = "; //visualize
	return ((float)this->_fixed_point_nb / (1 << Fixed::_fractional_bit));
}

/**
 * @brief convert fixed point value to integer value
 * @return integer value
*/
int	Fixed::toInt( void ) const
{
	//std::cout << "toInt member function called" << std::endl; //visualize
	//std::cout << this->_fixed_point_nb << ">>" << Fixed::_fractional_bit << " = "; //visualize
	return this->_fixed_point_nb >> Fixed::_fractional_bit;
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