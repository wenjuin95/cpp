/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:49:01 by welow             #+#    #+#             */
/*   Updated: 2025/02/20 20:27:01 by welow            ###   ########.fr       */
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
 * @brief convert the integer to fixed point
 * @param nb integer value to convert
 * @note 1. EXAMPLE : [ 10 << 8 ] => [ 10 * 2^8 ] => [ 10 * 256 = 2560 ]
*/
Fixed::Fixed( int const nb ) : _fixed_point_nb(nb << Fixed::_fractional_bit)
{
	if (CALL == 1)
		std::cout << "Int constructor called"<< std::endl;
}

/**
 * @brief convert the float to fixed point
 * @param nb float value to convert
 * @note 1. EXAMPLE : [ roundf(42.42 * (1 << 8)) ] => [ roundf(42.42 * 2^8) ] => [ roundf(42.42 * 256) = 10837 ]
*/
Fixed::Fixed( float const nb ) : _fixed_point_nb(roundf(nb * (1 << Fixed::_fractional_bit)))
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
	if (this != &src)
		this->_fixed_point_nb = src._fixed_point_nb;
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
	if (this->_fixed_point_nb > src._fixed_point_nb)
		return true;
	return false;
}

bool	Fixed::operator<(Fixed const &src) const
{
	if (this->_fixed_point_nb < src._fixed_point_nb)
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const &src) const
{
	if (this->_fixed_point_nb >= src._fixed_point_nb)
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const &src) const
{
	if (this->_fixed_point_nb <= src._fixed_point_nb)
		return true;
	return false;
}

bool	Fixed::operator==(Fixed const &src) const
{
	if (this->_fixed_point_nb == src._fixed_point_nb)
		return true;
	return false;
}

bool	Fixed::operator!=(Fixed const &src) const
{
	if (this->_fixed_point_nb != src._fixed_point_nb)
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
 * @note this get the object and increase the value by 1
*/
Fixed	&Fixed::operator++(void)
{
	if (CALL == 1)
		std::cout << "pre-increament operator called" << std::endl;
	this->_fixed_point_nb++;
	return *this;
}

/**
 * @brief pre-decreament operator
 * @return *this
 * @note this get the object and decrease the value by 1
*/
Fixed	&Fixed::operator--(void)
{
	if (CALL == 1)
		std::cout << "pre-decreament operator called" << std::endl;
	this->_fixed_point_nb--;
	return *this;
}

/**
 * @brief post-increament operator
 * @return tmp
 * @note 1. make a copy of the object
 * @note 2. increase the object by 1
 * @note 3. return the copy object
 * @note 4. return the object after increase
*/
Fixed	Fixed::operator++(int)
{
	if (CALL == 1)
		std::cout << "post-increament operator called" << std::endl;
	Fixed tmp(*this);
	operator++();
	return tmp;
}

/**
 * @brief post-decreament operator
 * @return tmp
*/
Fixed	Fixed::operator--(int)
{
	if (CALL == 1)
		std::cout << "post-decreament operator called" << std::endl;
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
 * @brief when "std::cout" is called, this function will be called to do other operation
 * @param output output stream
 * @param src copy of the value
 * @return output stream
 * @note it convert output to floating point value (pdf require)
*/
std::ostream	&operator<<(std::ostream &output, Fixed const &src)
{
	output << src.toFloat();
	return output;
}
