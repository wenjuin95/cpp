/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:49:01 by welow             #+#    #+#             */
/*   Updated: 2025/01/10 19:05:30 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief call default constructor with init the "_raw" with 0
*/
Fixed::Fixed() : _raw(0)
{
	if (CALL == 1)
		std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief call constructor with init the "_raw" with the value of "nb"
 * @param nb value in int
*/
Fixed::Fixed( int const nb ) : _raw(nb << Fixed::_bit)
{
	if (CALL == 1)
		std::cout << "Int constructor called"<< std::endl;
}

/**
 * @brief call constructor with init the "_raw" with the value of "nb"
 * @param nb value in float
*/
Fixed::Fixed( float const nb ) : _raw(roundf(nb * (1 << Fixed::_bit)))
{
	if (CALL == 1)
		std::cout << "Float constructor called" << std::endl;
}

/**
 * @brief copy constructor
 * @param src source to copy
 * @note "*this" is a pointer to the object itself
*/
Fixed::Fixed(const Fixed &src)
{
	if (CALL == 1)
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
	if (CALL == 1)
		std::cout << "Copy assignment operator called" << std::endl;
	this->_raw = src.getRawBits();
	return *this;
}

/**
 * @brief destructor
*/
Fixed::~Fixed()
{
	if (CALL == 1)
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
	//std::cout << this->_raw << "/" << (1 << Fixed::_bit) << std::endl;
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
/**
 * @brief pre-increament operator
 * @return *this
*/
Fixed	&Fixed::operator++(void)
{
	this->_raw++;
	return *this;
}

/**
 * @brief post-increament operator
 * @return tmp
*/
Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

/**
 * @brief pre-decreament operator
 * @return *this
*/
Fixed	&Fixed::operator--(void)
{
	this->_raw--;
	return *this;
}

/**
 * @brief post-decreament operator
 * @return tmp
*/
Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

/////////////////////////////////compare operators////////////////////////////////////////
/**
 * @brief look for the smallest value
 * @param a first value
 * @param b second value
 * @return the smallest value
*/
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return a;
	return b;
}

/**
 * @brief look for the smallest value (not changable)
 * @param a first value
 * @param b second value
 * @return the smallest value
*/
Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a <= b)
		return a;
	return b;
}

/**
 * @brief look for the biggest value
 * @param a first value
 * @param b second value
 * @return the biggest value
*/
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return a;
	return b;
}

/**
 * @brief look for the biggest value (not changable)
 * @param a first value
 * @param b second value
 * @return the biggest value
*/
Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a >= b)
		return a;
	return b;
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
	if (CALL == 1)
		std::cout << "output operator called" << std::endl;
	output << src.toFloat();
	return output;
}