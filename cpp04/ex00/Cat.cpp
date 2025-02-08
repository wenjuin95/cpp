/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-08 10:42:22 by welow             #+#    #+#             */
/*   Updated: 2025-02-08 10:42:22 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Cat.hpp"

Cat::Cat(void): Animal()
{
    if (CALL == 1) 
        std::cout << RED_H << "Cat (default constructor) called" << RESET << std::endl;
    this->_type = "Cat";

}

Cat::Cat(std::string type): Animal(type)
{
    if (CALL == 1)
        std::cout << RED_H << "Cat (constructor) called" << RESET << std::endl;
    this->_type = type;
}

Cat::Cat(const Cat &src): Animal(src)
{
    if (CALL == 1)
        std::cout << RED_H << "Cat (copy constructor) called" << RESET << std::endl;
    *this = src;
}

Cat &Cat::operator=(const Cat &src)
{
	if (CALL == 1)
		std::cout << RED_H << "Cat (assignment operator) called" << RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

Cat::~Cat(void)
{
	if (CALL == 1)
		std::cout << RED_H << "Cat (destructor) called" << RESET << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << this->_type << ": meow" << std::endl;
}