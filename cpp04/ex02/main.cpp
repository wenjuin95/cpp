/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:23:17 by welow             #+#    #+#             */
/*   Updated: 2025/02/14 16:49:48 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Animal.hpp"
#include "./include/Dog.hpp"
#include "./include/Cat.hpp"
#include <unistd.h>

#define nb_animal 10

int main()
{
    //this will cause an error because Animal is an abstract class
	// Animal *animal = new Animal();
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
    // {
    //     std::cout << "---------- create cat ----------" << std::endl;
    //     Cat *cat = new Cat();

    //     std::cout << std::endl << "---------- put idea to cat ----------" << std::endl;
    //     cat->setIdea(0, "I am a cat");
    //     std::cout << "cat idea 0: " << cat->getIdea(0) << std::endl;

    //     std::cout << std::endl << "---------- create copy cat ----------" << std::endl;
    //     Cat *copyCat = new Cat();
	// 	*copyCat = *cat;

	// 	cat->compareBoth(*copyCat);

    //     std::cout << std::endl << "---------- put new idea to cat ----------" << std::endl;
    //     cat->setIdea(0, "i like fish");
    //     std::cout << "cat new idea 0: " << cat->getIdea(0) << std::endl;

	// 	cat->compareBoth(*copyCat);

    //     std::cout << std::endl << "---------- set copy cat idea same with cat ----------" << std::endl;
    //     *copyCat = *cat;

	// 	cat->compareBoth(*copyCat);

    //     std::cout << std::endl << "---------- delete cat and copy cat ----------" << std::endl;
    //     delete cat;
    //     delete copyCat;
    // }
    // std::cout << "=============================================================================" << std::endl << std::endl;
    // {
    //     std::cout << "---------- create Dog ----------" << std::endl;
    //     Dog *dog = new Dog();

    //     std::cout << std::endl << "---------- put idea to Dog ----------" << std::endl;
    //     dog->setIdea(0, "I am a Dog");
    //     std::cout << "Dog idea 0: " << dog->getIdea(0) << std::endl;

    //     std::cout << std::endl << "---------- create copy Dog ----------" << std::endl;
    //     Dog *copyDog = new Dog(*dog);

	// 	dog->compareBoth(*copyDog);

    //     std::cout << std::endl << "---------- put new idea to Dog ----------" << std::endl;
    //     dog->setIdea(0, "i like bone");
    //     std::cout << "Dog new idea 0: " << dog->getIdea(0) << std::endl;

	// 	dog->compareBoth(*copyDog);

    //     std::cout << std::endl << "---------- set copy Dog idea same with Dog ----------" << std::endl;
    //     *copyDog = *dog;

	// 	dog->compareBoth(*copyDog);

    //     std::cout << std::endl << "---------- delete Dog and copy Dog ----------" << std::endl;
    //     delete dog;
    //     delete copyDog;
    // }
    // std::cout << "=============================================================================" << std::endl << std::endl;
}
