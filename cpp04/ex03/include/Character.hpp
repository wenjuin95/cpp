/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 07:33:16 by welow             #+#    #+#             */
/*   Updated: 2025-02-16 07:33:16 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define RED_H "\033[1;41m"
#define RESET "\033[0m"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_inventory[4];
    public:
        Character();
        Character(std::string const &name);
        Character(const Character &src);
        Character &operator=(const Character &src);
        ~Character();

        std::string const   &getName() const;
        void                setName(std::string &name);
        void                equip(AMateria *m);
        void                unequip(int idx);
        void                use(int idx, ICharacter &target);
        void                displayInventory();
};

#endif 