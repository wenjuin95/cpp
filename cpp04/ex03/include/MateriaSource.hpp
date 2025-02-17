/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 07:46:47 by welow             #+#    #+#             */
/*   Updated: 2025-02-16 07:46:47 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define YELLOW_H "\033[43m"
#define RESET "\033[0m"

class IMateriaSource;

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_materia[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &src);
        MateriaSource &operator=(const MateriaSource &src);
        ~MateriaSource();

        void        learnMateria(AMateria *m);
        AMateria    *createMateria(std::string const &type);
        void        displayMateria();
};

#endif