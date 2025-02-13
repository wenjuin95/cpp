/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:23:17 by welow             #+#    #+#             */
/*   Updated: 2025/02/13 13:53:26 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Animal.hpp"
#include "./include/Dog.hpp"
#include "./include/Cat.hpp"
#include "./include/WrongAnimal.hpp"
#include "./include/WrongCat.hpp"
#include <unistd.h>

#define nb_animal 10

int main()
{
	// {
	// 		std::cout << "Simple memory leaks test given from the subject.pdf" << std::endl;

	// 		const Animal* j = new Dog();
	// 		const Animal* i = new Cat();

	// 		delete j;//should not create a leak
	// 		delete i;
	// }
	// std::cout << "=============================================================================" << std::endl << std::endl;
	// {
	// 	std::cout << "Test for deep copy" << std::endl;

	// 	Dog	*dog1 = new Dog();
	// 	Dog	*dog2 = new Dog();

	// 	dog1->setIdea(0, "idea0"); // init some dog1 ideas
	// 	dog1->setIdea(1, "idea1");
	// 	*(Dog*)dog2 = *(Dog*)dog1; // copy dog1 to dog2
	// 	dog1->setIdea(2, "idea3"); // Add another idea for dog1
	// 	std::cout << "Dog1 idea 0: " << dog1->getIdea(0) << std::endl;
	// 	std::cout << "Dog1 idea 1: " << dog1->getIdea(1) << std::endl;
	// 	std::cout << "Dog1 idea 2: " << dog1->getIdea(2) << std::endl;
	// 	std::cout << std::endl;
	// 	std::cout << "Dog2 idea 0: " << dog2->getIdea(0) << std::endl;
	// 	std::cout << "Dog2 idea 1: " << dog2->getIdea(1) << std::endl;
	// 	std::cout << "Dog2 idea 2: " << dog2->getIdea(2) << std::endl; // Should be empty
	// 	std::cout << "Dog1 mem addr: " << &dog1 << std::endl;
	// 	std::cout << "Dog2 mem addr: " << &dog2 << std::endl;
	// 	delete dog1;
	// 	delete dog2;
	// }
	std::cout << "=============================================================================" << std::endl << std::endl;
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
        std::cout << "---------- create cat ----------" << std::endl;
        Cat *cat = new Cat();

        std::cout << std::endl << "---------- put idea to cat ----------" << std::endl;
        cat->setIdea(0, "I am a cat");
        std::cout << "cat idea 0: " << cat->getIdea(0) << std::endl;

        std::cout << std::endl << "---------- create copy cat ----------" << std::endl;
        Cat *copyCat = new Cat(*cat);

		cat->compareBoth(*copyCat);

        std::cout << std::endl << "---------- put new idea to cat ----------" << std::endl;
        cat->setIdea(0, "i like fish");
        std::cout << "cat new idea 0: " << cat->getIdea(0) << std::endl;

		cat->compareBoth(*copyCat);

        std::cout << std::endl << "---------- set copy cat idea same with cat ----------" << std::endl;
        *copyCat = *cat;

		cat->compareBoth(*copyCat);

        std::cout << std::endl << "---------- delete cat and copy cat ----------" << std::endl;
        delete cat;
        delete copyCat;
    }
    std::cout << "=============================================================================" << std::endl << std::endl;
    {
        std::cout << "---------- create Dog ----------" << std::endl;
        Dog *dog = new Dog();

        std::cout << std::endl << "---------- put idea to Dog ----------" << std::endl;
        dog->setIdea(0, "I am a Dog");
        std::cout << "Dog idea 0: " << dog->getIdea(0) << std::endl;

        std::cout << std::endl << "---------- create copy Dog ----------" << std::endl;
        Dog *copyDog = new Dog(*dog);

		dog->compareBoth(*copyDog);

        std::cout << std::endl << "---------- put new idea to Dog ----------" << std::endl;
        dog->setIdea(0, "i like bone");
        std::cout << "Dog new idea 0: " << dog->getIdea(0) << std::endl;

		dog->compareBoth(*copyDog);

        std::cout << std::endl << "---------- set copy Dog idea same with Dog ----------" << std::endl;
        *copyDog = *dog;

		dog->compareBoth(*copyDog);

        std::cout << std::endl << "---------- delete Dog and copy Dog ----------" << std::endl;
        delete dog;
        delete copyDog;
    }
    std::cout << "=============================================================================" << std::endl << std::endl;
}
