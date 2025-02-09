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
    {
        std::cout << "---------- wrong animal ----------" << std::endl;
        WrongAnimal *wronganimal = new WrongAnimal();
        std::cout << "type: " << wronganimal->getType() << std::endl;
        wronganimal->makeSound();
        delete wronganimal;

        std::cout << std::endl << "---------- wrong cat ----------" << std::endl;
        WrongCat *wrongcat = new WrongCat();
        std::cout << "type: " << wrongcat->getType() << std::endl;
        wrongcat->makeSound();
        delete wrongcat;
        
        //use parent class to create child class object
        //the makeSound() function will follow the child class because of the virtual function
        std::cout << std::endl << "---------- wrong cat from parent class ----------" << std::endl;
        WrongAnimal *wrongcat_parent = new WrongCat();
        std::cout << "type: " << wrongcat_parent->getType() << std::endl;
        wrongcat_parent->makeSound();
        delete wrongcat_parent;
    }
    std::cout << "=============================================================================" << std::endl << std::endl;
    {
        std::cout << "---------- animal ----------" << std::endl;
        Animal *animal = new Animal();
        std::cout << "type: " << animal->getType() << std::endl;
        animal->makeSound();
        delete animal;
        
        std::cout << std::endl << "---------- cat ----------" << std::endl;
        Cat *cat = new Cat();
        std::cout << "type: " << cat->getType() << std::endl;
        cat->makeSound();
        delete cat;

        std::cout << std::endl << "---------- cat from parent ----------" << std::endl;
        Animal *cat_parent = new Cat();
        std::cout << "type: " << cat_parent->getType() << std::endl;
        cat_parent->makeSound();
        delete cat_parent;

        std::cout << std::endl << "---------- dog ----------" << std::endl;
        Dog *dog = new Dog();
        std::cout << "type: " << dog->getType() << std::endl;
        dog->makeSound();
        delete dog;

        std::cout << std::endl << "---------- dog from parent ----------" << std::endl;
        Animal *dog_parent = new Dog();
        std::cout << "type: " << dog_parent->getType() << std::endl;
        dog_parent->makeSound();
        delete dog_parent;
    }
    std::cout << "=============================================================================" << std::endl << std::endl;

}
