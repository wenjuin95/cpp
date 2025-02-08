/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-08 11:23:17 by welow             #+#    #+#             */
/*   Updated: 2025-02-08 11:23:17 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Animal.hpp"
#include "./include/Dog.hpp"
#include "./include/Cat.hpp"
#include "./include/WrongAnimal.hpp"
#include "./include/WrongCat.hpp"

int main()
{
    {
        std::cout << "---------- wrong animal ----------" << std::endl;
        WrongAnimal *wronganimal = new WrongAnimal();
        std::cout << "type: " << wronganimal->getType() << std::endl;
        wronganimal->makeSound();
        delete wronganimal;
        
        std::cout << "---------- wrong cat ----------" << std::endl;
        WrongAnimal *wrongcat = new WrongCat();
        std::cout << "type: " << wrongcat->getType() << std::endl;
        wrongcat->makeSound();
        delete wrongcat;
    }
    std::cout << "=============================================================================" << std::endl << std::endl;
    {
        std::cout << "---------- subject ----------" << std::endl;
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete j;
        delete i;
        delete meta;
    }
    std::cout << "=============================================================================" << std::endl << std::endl;
}