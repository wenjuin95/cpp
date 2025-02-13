/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 06:40:20 by welow             #+#    #+#             */
/*   Updated: 2025/02/13 12:36:31 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Brain.hpp"

Brain::Brain(void)
{
    if (CALL == 1)
        std::cout << "Brain (default constructor) called" << std::endl;
}

Brain::Brain(std::string idea)
{
    if (CALL == 1)
        std::cout << "Brain (constructor) called" << std::endl;
    for (int i = 0; i < 100; i++)
        _idea[i] = idea;
}

Brain::Brain(const Brain &src)
{
    if (CALL == 1)
        std::cout << "Brain (copy constructor) called" << std::endl;
    *this = src;
}

Brain &Brain::operator=(const Brain &src)
{
    if (CALL == 1)
        std::cout << "Brain (assignment operator) called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_idea[i] = src._idea[i];
    return *this;
}

Brain::~Brain(void)
{
    if (CALL == 1)
        std::cout << "Brain (destructor) called" << std::endl;
}

const std::string &Brain::getIdea(int index) const
{
	if (index < 0)
        index = 0;
	else if (index >= 100)
		index = 99;
    return (_idea[index]);
}

void Brain::setIdea(int index, std::string idea)
{
    if (index < 0 || index >= 100)
        return ;
    this->_idea[index] = idea;
}
