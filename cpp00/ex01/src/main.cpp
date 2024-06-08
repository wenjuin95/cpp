/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:06:03 by welow             #+#    #+#             */
/*   Updated: 2024/06/08 17:27:25 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "contact.hpp"
// #include "phonebook.hpp"

// int main(int ac, char **av)
// {
// 	if (ac > 1)
// 		std::cout << "only program name is allowed\n";
// }





#include <iostream>

/******************FOR ACCESS PRIVATE**********************/
class Car{
	private:
		std::string brand;
		std::string model;
		int year;
	public:
		void set_brand(std::string b);
		void set_model(std::string m);
		void set_year(int y);
		std::string get_brand();
		std::string get_model();
		int get_year();
		void print_car();
};

void Car::set_brand(std::string b){
	brand = b;
}

void Car::set_model(std::string m){
	model = m;
}

void Car::set_year(int y){
	year = y;
}

std::string Car::get_brand()
{
	return brand;
}

std::string Car::get_model()
{
	return model;
}

int Car::get_year()
{
	return year;
}

void Car::print_car()
{
	std::cout << "Car brand: " << brand << std::endl;
	std::cout << "Car model: " << model << std::endl;
	std::cout << "Car year: " << year << std::endl;
}

int main()
{
	Car c1;
	std::cout << "without default constructor" << std::endl;
	c1.print_car();
	std::cout << std::endl;

	c1.set_brand("Toyota");
	c1.set_model("Vios");
	c1.set_year(2021);
	c1.print_car();
}
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