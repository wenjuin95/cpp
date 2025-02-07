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

#include "Animal.hpp"

Animal::Animal(void) : _type("Default type")
{
	if (CALL == 1)
		std::cout << "Anime (default constructor) called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	if (CALL == 1)
		std::cout << "Anime (constructor) called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	if (CALL == 1)
		std::cout << "Anime (copy constructor) called" << std::endl;
	*this = src;
}

Animal &Animal::operator=(const Animal &src)
{
	if (CALL == 1)
		std::cout << "Anime (assignment operator) called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

Animal::~Animal(void)
{
	if (CALL == 1)
		std::cout << "Anime (destructor) called" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound(void) const
{
	std::cout << this->_type << " sound" << std::endl;
}