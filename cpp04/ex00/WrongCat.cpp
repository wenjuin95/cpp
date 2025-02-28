/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:18:53 by welow             #+#    #+#             */
/*   Updated: 2025/02/28 21:01:59 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
    if (CALL == 1)
        std::cout << PURPLE_H << "WrongCat (default constructor) called" << RESET << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(std::string type): WrongAnimal(type)
{
    if (CALL == 1)
        std::cout << PURPLE_H << "WrongCat (constructor) called" << RESET << std::endl;
    this->_type = type;
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src)
{
    if (CALL == 1)
        std::cout << PURPLE_H << "WrongCat (copy constructor) called" << RESET << std::endl;
    *this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	if (CALL == 1)
		std::cout << PURPLE_H << "WrongCat (assignment operator) called" << RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	if (CALL == 1)
		std::cout << PURPLE_H << "WrongCat (destructor) called" << RESET << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << this->_type << ": meow" << std::endl;
}