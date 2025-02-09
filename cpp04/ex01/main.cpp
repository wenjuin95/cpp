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

#define nb_animal 10

int main()
{
    {
        std::cout << "---------- animal ----------" << std::endl;
        Animal *animalArray[nb_animal + 1];
        animalArray[nb_animal] = NULL;

        std::cout << "Create [" << nb_animal << "] animals"
                    << " with [" << nb_animal / 2 << "] of cat and"
                    << " [" << nb_animal / 2 << "] of dog" << std::endl;
        
        for (int i = 0; i < nb_animal / 2; i++)
            animalArray[i] = new Cat();
        std::cout << std::endl;
        for (int i = nb_animal / 2; i < nb_animal; i++)
            animalArray[i] = new Dog();

        std::cout << std::endl << "---------- cat and dog sound ----------" << std::endl;
        for (int i = 0; animalArray[i] != NULL; i++)
            animalArray[i]->makeSound();
        
        std::cout << std::endl << "---------- delete animal ----------" << std::endl;
        for (int i = 0; animalArray[i] != NULL; i++)
            delete animalArray[i];
        std::cout << std::endl;
    }
    std::cout << "=============================================================================" << std::endl << std::endl;
    {
        std::cout << "---------- cat ----------" << std::endl;
        Cat *cat = new Cat();

        std::cout << std::endl << "---------- put idea to cat ----------" << std::endl; 
        cat->getBrain()->setIdea(0, "I am a cat");
        cat->getBrain()->setIdea(1, "I am a cat too");
        cat->getBrain()->setIdea(2, "I am a cat too too");
        std::cout << "cat idea 0: " << cat->getBrain()->getIdea(0) << std::endl;
        std::cout << "cat idea 1: " << cat->getBrain()->getIdea(1) << std::endl;
        std::cout << "cat idea 2: " << cat->getBrain()->getIdea(2) << std::endl;

        std::cout << std::endl << "---------- copy cat ----------" << std::endl;
        Cat *copyCat = new Cat(*cat);

        std::cout << std::endl << "---------- copy cat idea must same with cat ----------" << std::endl;
        std::cout << "copy cat idea 0: " << copyCat->getBrain()->getIdea(0) << std::endl;
        std::cout << "copy cat idea 1: " << copyCat->getBrain()->getIdea(1) << std::endl;
        std::cout << "copy cat idea 2: " << copyCat->getBrain()->getIdea(2) << std::endl;

        std::cout << std::endl << "---------- new idea to cat ----------" << std::endl;
        cat->getBrain()->setIdea(0, "i like fish");
        cat->getBrain()->setIdea(1, "i like fish too");
        cat->getBrain()->setIdea(2, "i like fish too too");
        std::cout << "cat new idea 0: " << cat->getBrain()->getIdea(0) << std::endl;
        std::cout << "cat new idea 1: " << cat->getBrain()->getIdea(1) << std::endl;
        std::cout << "cat new idea 2: " << cat->getBrain()->getIdea(2) << std::endl;

        std::cout << std::endl << "---------- copy cat idea not change ----------" << std::endl;
        std::cout << "copy cat idea 0: " << copyCat->getBrain()->getIdea(0) << std::endl;
        std::cout << "copy cat idea 1: " << copyCat->getBrain()->getIdea(1) << std::endl;
        std::cout << "copy cat idea 2: " << copyCat->getBrain()->getIdea(2) << std::endl;

        std::cout << std::endl << "---------- set copy cat idea same with cat ----------" << std::endl; 
        *copyCat = *cat;

        std::cout << std::endl << "---------- copy cat idea had change to cat new idea ----------" << std::endl;
        std::cout << "copy cat idea 0: " << copyCat->getBrain()->getIdea(0) << std::endl;
        std::cout << "copy cat idea 1: " << copyCat->getBrain()->getIdea(1) << std::endl;
        std::cout << "copy cat idea 2: " << copyCat->getBrain()->getIdea(2) << std::endl;

        std::cout << std::endl << "---------- delete cat and copy cat ----------" << std::endl;
        delete cat;
        delete copyCat;
    }
    std::cout << "=============================================================================" << std::endl << std::endl;
    {
        std::cout << "---------- dog ----------" << std::endl;
        Dog *dog = new Dog();

        std::cout << std::endl << "---------- put idea to dog ----------" << std::endl; 
        dog->getBrain()->setIdea(0, "I am a dog");
        dog->getBrain()->setIdea(1, "I am a dog too");
        dog->getBrain()->setIdea(2, "I am a dog too too");
        std::cout << "dog idea 0: " << dog->getBrain()->getIdea(0) << std::endl;
        std::cout << "dog idea 1: " << dog->getBrain()->getIdea(1) << std::endl;
        std::cout << "dog idea 2: " << dog->getBrain()->getIdea(2) << std::endl;

        std::cout << std::endl << "---------- copy dog ----------" << std::endl;
        Dog *copydog = new Dog(*dog);

        std::cout << std::endl << "---------- copy dog idea must same with dog ----------" << std::endl;
        std::cout << "copy dog idea 0: " << copydog->getBrain()->getIdea(0) << std::endl;
        std::cout << "copy dog idea 1: " << copydog->getBrain()->getIdea(1) << std::endl;
        std::cout << "copy dog idea 2: " << copydog->getBrain()->getIdea(2) << std::endl;

        std::cout << std::endl << "---------- new idea to dog ----------" << std::endl;
        dog->getBrain()->setIdea(0, "i like bone");
        dog->getBrain()->setIdea(1, "i like bone too");
        dog->getBrain()->setIdea(2, "i like bone too too");
        std::cout << "dog new idea 0: " << dog->getBrain()->getIdea(0) << std::endl;
        std::cout << "dog new idea 1: " << dog->getBrain()->getIdea(1) << std::endl;
        std::cout << "dog new idea 2: " << dog->getBrain()->getIdea(2) << std::endl;

        std::cout << std::endl << "---------- copy dog idea not change ----------" << std::endl;
        std::cout << "copy dog idea 0: " << copydog->getBrain()->getIdea(0) << std::endl;
        std::cout << "copy dog idea 1: " << copydog->getBrain()->getIdea(1) << std::endl;
        std::cout << "copy dog idea 2: " << copydog->getBrain()->getIdea(2) << std::endl;

        std::cout << std::endl << "---------- set copy dog idea same with dog ----------" << std::endl; 
        *copydog = *dog;

        std::cout << std::endl << "---------- copy dog idea had change to dog new idea ----------" << std::endl;
        std::cout << "copy dog idea 0: " << copydog->getBrain()->getIdea(0) << std::endl;
        std::cout << "copy dog idea 1: " << copydog->getBrain()->getIdea(1) << std::endl;
        std::cout << "copy dog idea 2: " << copydog->getBrain()->getIdea(2) << std::endl;

        std::cout << std::endl << "---------- delete dog and copy dog ----------" << std::endl;
        delete dog;
        delete copydog;
    }
    std::cout << "=============================================================================" << std::endl << std::endl;

}
