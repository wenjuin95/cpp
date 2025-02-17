/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 08:20:14 by welow             #+#    #+#             */
/*   Updated: 2025-02-16 08:20:14 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

#define GREEN_H "\033[0;42m"
#define RESET "\033[0m"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &src);
        Cure &operator=(const Cure &src);
        ~Cure();

        AMateria *clone() const;
        void use(ICharacter &target);
};

#endif