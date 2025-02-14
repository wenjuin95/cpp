/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:42:22 by welow             #+#    #+#             */
/*   Updated: 2025/02/14 14:15:59 by welow            ###   ########.fr       */
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
    this->_brain = new Brain(*src._brain);
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
		Brain *tmp = new Brain(*src._brain);
		*tmp = *src._brain;
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = tmp;
    }
	return (*this);
}

Cat::~Cat(void)
{
	if (CALL == 1)
		std::cout << RED_H << "Cat (destructor) called" << RESET << std::endl;
	delete this->_brain;
}

void Cat::makeSound(void) const
{
	std::cout << this->_type << ": meow" << std::endl;
}

void Cat::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

const std::string &Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

void Cat::compareBoth(const Cat &other) const
{
	std::cout << std::endl << "++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "+      COMPARING CAT AND COPIED CAT            +" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "This Cat's brain address: " << this->_brain << std::endl;
	std::cout << "copied Cat's brain address: " << other._brain << std::endl;

	std::cout << std::endl << "this cat idea" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << i + 1 << ": "<< this->_brain->getIdea(i) << " (" << this->_brain << ")" << std::endl;

	std::cout << std::endl << "copied cat idea" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << i + 1 << ": "<< other._brain->getIdea(i) << " (" << other._brain << ")" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}
