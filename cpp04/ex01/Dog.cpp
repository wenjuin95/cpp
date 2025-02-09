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
    this->_brain = new Brain();
}

Dog::Dog(std::string type): Animal(type)
{
    if (CALL == 1)
        std::cout << YELLOW_H << "Dog (constructor) called" << RESET << std::endl;
    this->_type = type;
    this->_brain = new Brain();
}

Dog::Dog(const Dog &src): Animal(src)
{
    if (CALL == 1)
        std::cout << YELLOW_H << "Dog (copy constructor) called" << RESET << std::endl;
    this->_brain = NULL;
    *this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	if (CALL == 1)
		std::cout << YELLOW_H << "Dog (assignment operator) called" << RESET << std::endl;
	if (this != &src)
    {
		this->_type = src._type;
        if (this->_brain != NULL)
            delete this->_brain;
        this->_brain = new Brain(*src._brain);
    }
	return (*this);
}

Dog::~Dog(void)
{
	if (CALL == 1)
		std::cout << YELLOW_H << "Dog (destructor) called" << RESET << std::endl;
    if (this->_brain != NULL)
        delete this->_brain;
    this->_brain = NULL;
}

void Dog::makeSound(void) const
{
	std::cout << this->_type << ": bark" << std::endl;
}

Brain *Dog::getBrain(void) const
{
    return (this->_brain);
}