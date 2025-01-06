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

Fixed::Fixed( int const nb )
{
	std::cout << "Int constructor called"<< std::endl;
	//std::cout << "nb :" << nb << std::endl; //visualize
	this->_raw = nb << Fixed::_bit; //convert the integer to fixed point
	//std::cout << "fixed point nb: " << this->_raw << std::endl << std::endl; //visualize
}

Fixed::Fixed( float const nb )
{
	std::cout << "Float constructor called" << std::endl;
	//std::cout << "nb :" << nb << std::endl; //visualize
	this->_raw = roundf(nb * (1 << Fixed::_bit)); //convert the float to fixed point
	//std::cout << "fixed point nb: " << this->_raw << std::endl << std::endl; //visualize
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
 * @brief convert value to float
 * @return float value of the fixed point value
*/
float	Fixed::toFloat( void ) const
{
	//1 << 8 = 256
	//std::cout << "toFloat member function called" << std::endl; //visualize
	//std::cout << (float)this->_raw  << "/" << (1 << Fixed::_bit) << " = "; //visualize
	return ((float)this->_raw / (1 << Fixed::_bit));
}

/**
 * @brief convert value to int
 * @return integer value of the fixed point value
*/
int	Fixed::toInt( void ) const
{
	//std::cout << "toInt member function called" << std::endl; //visualize
	//std::cout << this->_raw << ">>" << Fixed::_bit << " = "; //visualize
	return this->_raw >> Fixed::_bit;
}

/**
 * @brief when "std::cout" is called, this function will be called
 * @param output output stream
 * @param src copy of the value
 * @return output stream
 * @note output the float value
*/
std::ostream	&operator<<(std::ostream &output, Fixed const &src)
{
	output << src.toFloat();
	return output;
}