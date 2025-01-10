/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:49:01 by welow             #+#    #+#             */
/*   Updated: 2025/01/09 19:10:09 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief call default constructor with init the "_raw" with 0
*/
Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief call constructor with init the "_raw" with the value of "nb"
 * @param nb value in int
*/
Fixed::Fixed( int const nb ) : _raw(nb << Fixed::_bit)
{
	std::cout << "Int constructor called"<< std::endl;
}

/**
 * @brief call constructor with init the "_raw" with the value of "nb"
 * @param nb value in float
*/
Fixed::Fixed( float const nb ) : _raw(roundf(nb * (1 << Fixed::_bit)))
{
	std::cout << "Float constructor called" << std::endl;
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

/**
 * @brief destructor
*/
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
	return ((float)this->_raw / (1 << Fixed::_bit));
}

/**
 * @brief convert value to int
 * @return integer value of the fixed point value
*/
int	Fixed::toInt( void ) const
{
	return this->_raw >> Fixed::_bit;
}

//////////////////////////////Comparison operators//////////////////////////////////////
bool	Fixed::operator>(Fixed const &src) const
{
	if (this->_raw > src.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<(Fixed const &src) const
{
	if (this->_raw < src.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const &src) const
{
	if (this->_raw >= src.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const &src) const
{
	if (this->_raw <= src.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(Fixed const &src) const
{
	if (this->_raw == src.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(Fixed const &src) const
{
	if (this->_raw != src.getRawBits())
		return true;
	return false;
}

//////////////////////////////Arithmetric operators//////////////////////////////////////
Fixed	Fixed::operator+(Fixed const &src) const
{
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed	Fixed::operator-(Fixed const &src) const
{
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed	Fixed::operator*(Fixed const &src) const
{
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed	Fixed::operator/(Fixed const &src) const
{
	return Fixed(this->toFloat() / src.toFloat());
}

//////////////////////////////increament/decreament operators//////////////////////////////////////
Fixed	&Fixed::operator++(void)
{
	this->_raw++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

/////////////////////////////////Output operators////////////////////////////////////////
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