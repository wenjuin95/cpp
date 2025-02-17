/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 08:23:03 by welow             #+#    #+#             */
/*   Updated: 2025-02-16 08:23:03 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

#define CYAN_H "\033[0;46m"
#define RESET "\033[0m"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &src);
        Ice &operator=(const Ice &src);
        ~Ice();

        AMateria *clone() const;
        void use(ICharacter &target);
};

#endif