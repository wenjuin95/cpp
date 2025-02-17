/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 09:52:44 by welow             #+#    #+#             */
/*   Updated: 2025-02-16 09:52:44 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/MateriaSource.hpp"
#include <iomanip>

MateriaSource::MateriaSource(void)
{
    if (CALL == 1)
        std::cout << YELLOW_H << "MateriaSource (default constructor) called" << RESET << std::endl;
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
    return ;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    if (CALL == 1)
        std::cout << YELLOW_H << "MateriaSource (copy constructor) called" << RESET << std::endl;
    *this = src;
    return ;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    if (CALL == 1)
        std::cout << YELLOW_H << "MateriaSource (assignment operator) called" << RESET << std::endl;
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
            if (this->_materia[i] != NULL)
            {
                delete this->_materia[i];
                this->_materia[i] = NULL;
            }
        for (int i = 0; i < 4; i++)
            if (src._materia[i] != NULL)
            {
                this->_materia[i] = src._materia[i]->clone();
            }
    }
    return (*this);
}

MateriaSource::~MateriaSource(void)
{
    if (CALL == 1)
        std::cout << YELLOW_H << "MateriaSource (destructor) called" << RESET << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->_materia[i] != NULL)
            delete this->_materia[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (m == NULL)
    {
        std::cout << "MateriaSource has no materia to learn" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] == NULL)
        {
            this->_materia[i] = m;
            std::cout << "MateriaSource learned [" << this->_materia[i]->getType() << "] materia" << std::endl;
            return ;
        }
    }
    std::cout << "MateriaSource is full" << std::endl;
    delete m;
    return ;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
        {
            std::cout << "MateriaSource create [" << type << "] materia" << std::endl;
            return (this->_materia[i]->clone());
        }
    }
    std::cout << "MateriaSource can't create [" << type << "] materia" << std::endl;
    return (NULL);
}

void MateriaSource::displayMateria(void)
{
    std::cout << "+------+------+------+------+" << std::endl;
    std::cout << "|      Materia Source       |" << std::endl;
    std::cout << "+---------------------------+" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] != NULL)
        {
            std::cout << "|" << std::setw(5) << this->_materia[i]->getType() << "(" << this->_materia[i] << ")" << std::setw(7) << " |" << std::endl;
            std::cout << "+---------------------------+" << std::endl;
        }
        else
        {
            std::cout << "|                           |" << std::endl;
            std::cout << "+---------------------------+" << std::endl;
        }
    }
}