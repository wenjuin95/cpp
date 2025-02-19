/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:49:01 by welow             #+#    #+#             */
/*   Updated: 2025/02/19 19:58:27 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief call default constructor with init the "_fixed_point_nb" with 0
*/
Fixed::Fixed() : _fixed_point_nb(0)
{
	if (CALL == 1)
		std::cout << BLUE_H << "Default constructor called" << RESET << std::endl;
}

/**
 * @brief call constructor with init the "_fixed_point_nb" with the value of "nb"
 * @param nb value in int
*/
Fixed::Fixed( int const nb )
{
	if (CALL == 1)
		std::cout << "Int constructor called"<< std::endl;
	this->_fixed_point_nb = nb << Fixed::_fractional_bit;
}

/**
 *
 * @brief call constructor with init the "_fixed_point_nb" with the value of "nb"
 * @param nb value in float
*/
Fixed::Fixed( float const nb )
{
	if (CALL == 1)
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
	if (CALL == 1)
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
	if (CALL == 1)
		std::cout << YELLOW_H << "Copy assignment operator called" << RESET << std::endl;
	this->_fixed_point_nb = src.getRawBits();
	return *this;
}

/**
 * @brief destructor
*/
Fixed::~Fixed()
{
	if (CALL == 1)
		std::cout << GREEN_H << "Destructor called" << RESET << std::endl;;
}

/**
 * @brief set the raw value
 * @param raw raw value to set
*/
void	Fixed::setRawBits( int const fixed_point_nb )
{
	this->_fixed_point_nb = fixed_point_nb;
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
 * @brief convert value to float
 * @return float value of the fixed point value
*/
float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixed_point_nb / (1 << Fixed::_fractional_bit));
}

/**
 * @brief convert value to int
 * @return integer value of the fixed point value
*/
int	Fixed::toInt( void ) const
{
	return this->_fixed_point_nb >> Fixed::_fractional_bit;
}

//////////////////////////////Comparison operators//////////////////////////////////////
bool	Fixed::operator>(Fixed const &src) const
{
	if (this->_fixed_point_nb > src.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<(Fixed const &src) const
{
	if (this->_fixed_point_nb < src.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const &src) const
{
	if (this->_fixed_point_nb >= src.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const &src) const
{
	if (this->_fixed_point_nb <= src.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(Fixed const &src) const
{
	if (this->_fixed_point_nb == src.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(Fixed const &src) const
{
	if (this->_fixed_point_nb != src.getRawBits())
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
	this->_fixed_point_nb++;
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
	this->_fixed_point_nb--;
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