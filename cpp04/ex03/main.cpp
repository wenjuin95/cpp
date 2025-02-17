/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 10:34:20 by welow             #+#    #+#             */
/*   Updated: 2025-02-16 10:34:20 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Character.hpp"
#include "./include/Cure.hpp"
#include "./include/Ice.hpp"
#include "./include/MateriaSource.hpp"

int main()
{
    // {
    //     IMateriaSource* src = new MateriaSource();
    //     src->learnMateria(new Ice());
    //     src->learnMateria(new Cure());
    //     src->displayMateria();
    
    //     ICharacter* me = new Character("me");
    //     AMateria* tmp;
    //     tmp = src->createMateria("ice");
    //     me->equip(tmp);
    //     tmp = src->createMateria("cure");
    //     me->equip(tmp);
    //     me->displayInventory();
        
    //     ICharacter* bob = new Character("bob");
        
    //     me->use(0, *bob);
    //     me->use(1, *bob);
        
    //     delete bob;
    //     delete me;
    //     delete src;
    // }
    // {
    //    MateriaSource *src = new MateriaSource();
    //    std::cout << std::endl << "----------display materia source----------" << std::endl;
    //    src->displayMateria();

    //    std::cout << std::endl << "----------learned materia source----------" << std::endl;
    //    src->learnMateria(NULL);
    //    src->learnMateria(new Ice());
    //    src->learnMateria(new Cure());
    //    src->displayMateria();

    //    MateriaSource *copySrc = new MateriaSource();
    //    *copySrc = *src;
    //    std::cout << std::endl << "----------src vs copy src (address must be different)----------" << std::endl;
    //    std::cout << "SRC: " << std::endl;
    //    src->displayMateria();
    //    std::cout << std::endl << "COPY SRC: " << std::endl;
    //    copySrc->displayMateria();

    //    std::cout << std::endl << "----------add new materia to src (address must be different)----------" << std::endl;
    //    src->learnMateria(new Ice());
    //    std::cout << "SRC: " << std::endl;
    //    src->displayMateria();
    //    std::cout << std::endl << "COPY SRC: " << std::endl;
    //    copySrc->displayMateria();

    //    std::cout << std::endl << "----------make copy src similar to src (address must be different)----------" << std::endl;
    //    *copySrc = *src;
    //    std::cout << "SRC: " << std::endl;
    //    src->displayMateria();
    //    std::cout << std::endl << "COPY SRC: " << std::endl;
    //    copySrc->displayMateria();

    //    delete src;
    //    delete copySrc;
    // }
    // {
    //     IMateriaSource *book = new MateriaSource();
    //     book->learnMateria(new Ice());
    //     book->learnMateria(new Cure());
    //     std::cout << std::endl << "----------display materia source----------" << std::endl;
    //     book->displayMateria();

    //     std::cout << std::endl << "----------jill copy jack skill (address must be different)----------" << std::endl;
    //     Character *jack = new Character("Jack");
    //     jack->equip(book->createMateria("ice"));
    //     jack->equip(book->createMateria("cure"));
    //     std::cout << std::endl << "jack skill:" << std::endl;
    //     jack->displayInventory();

    //     Character *jill = new Character("Jill");
    //     *jill = *jack;
    //     std::cout << std::endl << "jill skill:" << std::endl;
    //     jill->displayInventory();

    //     delete jack;
    //     delete jill;
    //     delete book;
    // }
    return 0;
}
