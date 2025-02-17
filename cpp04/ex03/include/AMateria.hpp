/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMeteria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 07:22:18 by welow             #+#    #+#             */
/*   Updated: 2025-02-16 07:22:18 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#ifndef CALL
#define CALL 0
#endif

#include <iostream>
#include <string>
#include "ICharacter.hpp"

#define BLUE_H "\033[1;44m"
#define RESET "\033[0m"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria &src);
        AMateria &operator=(const AMateria &src);
        virtual ~AMateria();

        std::string const &getType() const;
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif