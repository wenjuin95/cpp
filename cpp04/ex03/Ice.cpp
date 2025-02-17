/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 10:31:47 by welow             #+#    #+#             */
/*   Updated: 2025-02-16 10:31:47 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    if (CALL == 1)
        std::cout << CYAN_H "Ice (default constructor) called" << RESET << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src)
{
    if (CALL == 1)
        std::cout << CYAN_H "Ice (copy constructor) called" << RESET << std::endl;
    *this = src;
}

Ice &Ice::operator=(const Ice &src)
{
    if (CALL == 1)
        std::cout << CYAN_H "Ice (assignment operator) called" << RESET << std::endl;
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

Ice::~Ice(void)
{
    if (CALL == 1)
        std::cout << CYAN_H "Ice (destructor) called" << RESET << std::endl;
}

AMateria *Ice::clone(void) const
{
    AMateria *clone = new Ice();
    return (clone);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at [" << target.getName() << "] *" << std::endl;
}