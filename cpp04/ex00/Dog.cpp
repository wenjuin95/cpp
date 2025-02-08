/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-08 11:13:18 by welow             #+#    #+#             */
/*   Updated: 2025-02-08 11:13:18 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Dog.hpp"

Dog::Dog(void): Animal()
{
    if (CALL == 1) 
        std::cout << YELLOW_H << "Dog (default constructor) called" << RESET << std::endl;
    this->_type = "Dog";
}

Dog::Dog(std::string type): Animal(type)
{
    if (CALL == 1)
        std::cout << YELLOW_H << "Dog (constructor) called" << RESET << std::endl;
    this->_type = type;
}

Dog::Dog(const Dog &src): Animal(src)
{
    if (CALL == 1)
        std::cout << YELLOW_H << "Dog (copy constructor) called" << RESET << std::endl;
    *this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	if (CALL == 1)
		std::cout << YELLOW_H << "Dog (assignment operator) called" << RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

Dog::~Dog(void)
{
	if (CALL == 1)
		std::cout << YELLOW_H << "Dog (destructor) called" << RESET << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << this->_type << ": bark" << std::endl;
}