/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:40:24 by welow             #+#    #+#             */
/*   Updated: 2025/02/07 20:54:58 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	if (CALL == 1)
		std::cout << BLUE_H << "Animal (default constructor) called" << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	if (CALL == 1)
		std::cout << BLUE_H << "Animal (constructor) called" << RESET << std::endl;
}

Animal::Animal(const Animal &src)
{
	if (CALL == 1)
		std::cout << BLUE_H << "Animal (copy constructor) called" << RESET << std::endl;
	*this = src;
}

Animal &Animal::operator=(const Animal &src)
{
	if (CALL == 1)
		std::cout << BLUE_H << "Animal (assignment operator) called" << RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

Animal::~Animal(void)
{
	if (CALL == 1)
		std::cout << BLUE_H << "Animal (destructor) called" << RESET << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound(void) const
{
	std::cout << this->_type << ": no sound" << std::endl;
}