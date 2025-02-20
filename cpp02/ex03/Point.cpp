/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:02:35 by welow             #+#    #+#             */
/*   Updated: 2025/02/20 20:54:36 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Default constructor
*/
Point::Point(void): _x(0), _y(0)
{
	if (CALL == 1)
		std::cout << "Point default constructor called" << std::endl;
}

/**
 * @brief Parameterized constructor
 * @param x x-coordinate
 * @param y y-coordinate
*/
Point::Point(Fixed const x, Fixed const y): _x(x), _y(y)
{
	if (CALL == 1)
		std::cout << "Point constructor called" << std::endl;
}

/**
 * @brief Copy constructor
 * @param src Point object to copy
 * @note 1. this copy need to copy the x and y value not the object itself
*/
Point::Point(Point const &src): _x(src.getX()), _y(src.getY())
{
	if (CALL == 1)
		std::cout << "Point copy constructor called" << std::endl;
}

/**
 * @brief Assignment operator
 * @param src Point object to copy
 * @return reference to this object
*/
Point &Point::operator=(Point const &src)
{
	if (CALL == 1)
		std::cout << "Point assignment operator called" << std::endl;
	(void)src;
	return (*this);
}

/**
 * @brief Destructor
*/
Point::~Point(void)
{
	if (CALL == 1)
		std::cout << "Point destructor called" << std::endl;
}

/**
 * @brief Get y-coordinate
 * @return y-coordinate
*/
Fixed const &Point::getY(void) const
{
	return (this->_y);
}

/**
 * @brief Get x-coordinate
 * @return x-coordinate
*/
Fixed const &Point::getX(void) const
{
	return (this->_x);
}
