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
    this->_brain = new Brain();
}

Cat::Cat(std::string type): Animal(type)
{
    if (CALL == 1)
        std::cout << RED_H << "Cat (constructor) called" << RESET << std::endl;
    this->_type = type;
    this->_brain = new Brain();
}

/**
 * @brief Copy constructor
 * @param src The object to do the copy
 * @return A new object copied from src
*/
Cat::Cat(const Cat &src): Animal(src)
{
    if (CALL == 1)
        std::cout << RED_H << "Cat (copy constructor) called" << RESET << std::endl;
    this->_brain = NULL;
    *this = src;
}

/**
 * @brief Assignment operator
 * @param src The object to do the copy
 * @return A new object copied from src
 * @note if the object not the same, delete the old object and create a new one
*/
Cat &Cat::operator=(const Cat &src)
{
	if (CALL == 1)
		std::cout << RED_H << "Cat (assignment operator) called" << RESET << std::endl;
	if (this != &src)
    {
		this->_type = src._type;
        if (this->_brain != NULL)
            delete this->_brain;
        this->_brain = new Brain(*src._brain);
    }
	return (*this);
}

Cat::~Cat(void)
{
	if (CALL == 1)
		std::cout << RED_H << "Cat (destructor) called" << RESET << std::endl;
    if (this->_brain != NULL)
        delete this->_brain;
    this->_brain = NULL;
}

void Cat::makeSound(void) const
{
	std::cout << this->_type << ": meow" << std::endl;
}

Brain *Cat::getBrain(void) const
{
    return (this->_brain);
}