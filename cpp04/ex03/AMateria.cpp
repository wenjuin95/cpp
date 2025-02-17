/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 08:24:24 by welow             #+#    #+#             */
/*   Updated: 2025-02-16 08:24:24 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/AMateria.hpp"

AMateria::AMateria(void) : _type("Default")
{
    if (CALL == 1)
        std::cout << BLUE_H << "AMateria (Default constructor) called" << RESET << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    if (CALL == 1)
        std::cout << BLUE_H << "AMateria (constructor) called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
    if (CALL == 1)
        std::cout << BLUE_H << "AMateria (Copy constructor) called" << RESET << std::endl;
    *this = src;
}

AMateria &AMateria::operator=(const AMateria &src)
{
    if (CALL == 1)
        std::cout << BLUE_H << "AMateria (assignment operator) called" << RESET << std::endl;
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

AMateria::~AMateria(void)
{
    if (CALL == 1)
        std::cout << BLUE_H << "AMateria (destructor) called" << RESET << std::endl;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "use [" << this->_type << "] on [" << target.getName() << "]" << std::endl;
}

std::string const &AMateria::getType(void) const
{
    return (this->_type);
}