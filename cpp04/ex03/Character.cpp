/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 08:52:40 by welow             #+#    #+#             */
/*   Updated: 2025-02-16 08:52:40 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Character.hpp"

Character::Character(void) : _name("default")
{
    if (CALL == 1)
        std::cout << RED_H << "Character (default constructor) called" << RESET << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(std::string const &name) : _name(name)
{
    if (CALL == 1)
        std::cout << RED_H << "Character (constructor) called" << RESET << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;        
}

Character::Character(const Character &src)
{
    if (CALL == 1)
        std::cout << RED_H << "Character (constructor) called" << RESET << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;      
    *this = src;
}

Character &Character::operator=(const Character &src)
{
    if (CALL == 1)
        std::cout << RED_H << "Character (assignment operator) called" << RESET << std::endl;
    if (this != &src)
    {
        _name = src._name;
        for (int i = 0; i < 4; i++)
            if (_inventory[i] != NULL)
                delete _inventory[i];
        for (int i = 0; i < 4; i++)
            if (src._inventory[i] != NULL)
                _inventory[i] = src._inventory[i]->clone();
    }
    return (*this);
}

Character::~Character(void)
{
    if (CALL == 1)
        std::cout << RED_H << "Character (destructor) called" << RESET << std::endl;
    for (int i = 0; i < 4; i++)
        if (_inventory[i] != NULL)
            delete _inventory[i];
}

std::string const   &Character::getName(void) const
{
    return (this->_name);
}

void    Character::setName(std::string &name)
{
    this->_name = name;
}

void    Character::equip(AMateria *m)
{
    if (m == NULL)
    {
        std::cout << "can't equip an unknown materia" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            std::cout << "equipped [" << m->getType() << "] materia to inventory ["
                << i << "]" << std::endl;
            return ;
        }
    }
    std::cout << "inventory is full" << std::endl;
    return ;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << "invalid index" << std::endl;
        return ;
    }
    if (this->_inventory[idx] == NULL)
    {
        std::cout << "inventory [" << idx << "] is empty" << std::endl;
        return ;
    }
    std::cout << "unequip [" << this->_inventory[idx]->getType()
        << "] materia from inventory [" << idx << "]" << std::endl;
    this->_inventory[idx] = NULL;
    return ;
}

void    Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 4)
    {
        std::cout << "invalid index" << std::endl;
        return ;
    }
    if (this->_inventory[idx] != NULL)
    {
        std::cout << "[" << this->_name << "] uses [" << this->_inventory[idx]->getType()
            << "] materia on [" << target.getName() << "]" << std::endl;
        this->_inventory[idx]->use(target);
    }
    else
    {
        std::cout << "inventory [" << idx << "] is empty" << std::endl;
    }
    return ;
}

void Character::displayInventory(void)
{
    std::cout << "+------+------+------+------+" << std::endl;
    std::cout << "|";
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] != NULL)
        {
            std::cout << " " << this->_inventory[i]->getType() << " |";
        }
        else
        {
            std::cout << "      |";
        }
    }
    std::cout << std::endl << "+------+------+------+------+" << std::endl;
}