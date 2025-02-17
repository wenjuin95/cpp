/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 10:10:29 by welow             #+#    #+#             */
/*   Updated: 2025-02-16 10:10:29 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
    if (CALL == 1)
        std::cout << GREEN_H << "Cure (default constructor) called" << RESET << std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src)
{
    if (CALL == 1)
        std::cout << GREEN_H << "Cure (copy constructor) called" << RESET << std::endl;
    *this = src;
}

Cure &Cure::operator=(const Cure &src)
{
    if (CALL == 1)
        std::cout << GREEN_H << "Cure (assignment operator) called" << RESET << std::endl;
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

Cure::~Cure(void)
{
    if (CALL == 1)
        std::cout << GREEN_H << "Cure (destructor) called" << RESET << std::endl;
}

AMateria *Cure::clone(void) const
{
    AMateria *clone = new Cure();
    return (clone);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals [" << target.getName() << "]'s wounds *" << std::endl;
}