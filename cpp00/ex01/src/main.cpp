/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:06:03 by welow             #+#    #+#             */
/*   Updated: 2024/06/17 18:13:03 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

std::string ft_toupper(std::string str);

int main(void)
{
	Phonebook phonebook;
	std::string input;
	
	std::cout << BLUE << "\tWELCOME TO PHONEBOOK\t\n" << RESET;
	while (1)
	{
		std::cout << "\n";
		std::cout << "+------------MAIN MENU------------+\n";
		std::cout << "| ADD: to add a new contact       |\n";
		std::cout << "| SEARCH: to search for a contact |\n";
		std::cout << "| EXIT: to exit the phonebook     |\n";
		std::cout << "+---------------------------------+\n";
		std::cout << "\rEnter your command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input); // get the input from the user
		input = ft_toupper(input);
		if (std::cin.eof()) // if the user press ctrl + D
		{
			std::cout << "\n";
			std::cout << GREEN << "EXIT PHONEBOOK\n" << RESET;
			break;
		}
		if (input.empty()) // if the user press enter
			continue;
		else
		{
			if(input == "ADD")
			{
				phonebook.add_contact();
			}
			// else if (input == "SEARCH")
			// 	phonebook.search_contact();
			else if (input == "EXIT")
			{
				std::cout << GREEN << "EXIT PHONEBOOK\n" << RESET;
				break;
			}
			else if (input == "SHOW")
				phonebook.display_contact();
			else
			{
				std::cout << RED << "Invalid command\n" << RESET;
				continue;
			}
			
		}
	}
	return (0);
}

std::string ft_toupper(std::string str)
{
	std::string res;
	int i = 0;
	while (str[i])
	{
		res += toupper(str[i]);
		i++;
	}
	return (res);
}



// #include <iostream>
// # include <iomanip>

// /******************FOR ACCESS PRIVATE**********************/
// class Car{
// 	private:
// 		std::string brand;
// 		std::string model;
// 		int year;
// 	public:
// 		void set_brand(std::string b);
// 		void set_model(std::string m);
// 		void set_year(int y);
// 		std::string get_brand();
// 		std::string get_model();
// 		int get_year();
// 		void print_car();
// };

// void Car::set_brand(std::string b){
// 	brand = b;
// }

// void Car::set_model(std::string m){
// 	model = m;
// }

// void Car::set_year(int y){
// 	year = y;
// }

// std::string Car::get_brand()
// {
// 	return brand;
// }

// std::string Car::get_model()
// {
// 	return model;
// }

// int Car::get_year()
// {
// 	return year;
// }

// void Car::print_car()
// {
// 	std::cout << "Car brand: " << brand << std::endl;
// 	std::cout << "Car model: " << model << std::endl;
// 	std::cout << "Car year: " << year << std::endl;
// }

// int main()
// {
// 	Car c1;
// 	std::cout << "without default constructor" << std::endl;
// 	c1.print_car();
// 	std::cout << std::endl;

// 	c1.set_brand("Toyota");
// 	c1.set_model("Vios");
// 	c1.set_year(2021);
// 	c1.print_car();
// }

/******************FOR ACCESS PUBLIC**********************/
// class Car
// {
// 	public:
// 		std::string brand;
// 		std::string model;
// 		int year;
// 		void print_car();
// };

// void Car::print_car()
// {
// 	std::cout << "Car brand: " << brand << std::endl;
// 	std::cout << "Car model: " << model << std::endl;
// 	std::cout << "Car year: " << year << std::endl;
// }

// int main()
// {
// 	Car c1;
// 	std::cout << "without default constructor" << std::endl;
// 	c1.print_car();
// 	std::cout << std::endl;

// 	c1.brand = "Toyota";
// 	c1.model = "Vios";
// 	c1.year = 2021;
// 	c1.print_car();
// }