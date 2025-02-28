
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-08 11:15:49 by welow             #+#    #+#             */
/*   Updated: 2025-02-08 11:15:49 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Animal")
{
	if (CALL == 1)
		std::cout << GREEN_H << "WrongAnimal (default constructor) called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	if (CALL == 1)
		std::cout << GREEN_H << "WrongAnimal (constructor) called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	if (CALL == 1)
		std::cout << GREEN_H << "WrongAnimal (copy constructor) called" << RESET << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	if (CALL == 1)
		std::cout << GREEN_H << "WrongAnimal (assignment operator) called" << RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	if (CALL == 1)
		std::cout << GREEN_H << "WrongAnimal (destructor) called" << RESET << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << this->_type << ": * no sound *" << std::endl;
}