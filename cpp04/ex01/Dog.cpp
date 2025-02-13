/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:13:18 by welow             #+#    #+#             */
/*   Updated: 2025/02/13 13:46:00 by welow            ###   ########.fr       */
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
    this->_brain = new Brain(*src._brain);
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
    delete this->_brain;
}

void Dog::makeSound(void) const
{
	std::cout << this->_type << ": bark" << std::endl;
}

void Dog::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

const std::string &Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

void Dog::compareBoth(const Dog &other) const
{
	std::cout << std::endl << "++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "+      COMPARING DOG AND COPIED DOG            +" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "This dog's brain address: " << this->_brain << std::endl;
	std::cout << "copied dog's brain address: " << other._brain << std::endl;

	std::cout << std::endl << "this dog idea" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << i + 1 << ": "<< this->_brain->getIdea(i) << std::endl;

	std::cout << std::endl << "copied dog idea" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << i + 1 << ": "<< other._brain->getIdea(i) << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}
