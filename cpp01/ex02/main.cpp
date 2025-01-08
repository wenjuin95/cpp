/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:40:59 by welow             #+#    #+#             */
/*   Updated: 2025/01/08 17:56:00 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	// "std::string" is just a string not "char *" or "char []"
	std::string str = "HI THIS IS BRAIN";
	// "&str" is the memory address of the string
	std::cout << "memory address of str      : " << &str << std::endl;
	// "str" is the value of the string
	std::cout << "value of the str           : " << str << std::endl << std::endl;

	// "stringPTR" is a pointer to the string
	//pointer only hold memory address as a value
	//std::string *stringPTR = NULL; //test
	//stringPTR = &str; //test
	std::string *stringPTR = &str;
	// "stringPTR" is the memory address of the string pointer
	std::cout << "memory address of stringPTR: " << stringPTR << std::endl;
	// "*stringPTR" is the value of the string pointer
	std::cout << "value of the stringPTR     : " << *stringPTR << std::endl << std::endl;

	// "stringREF" is a reference to the string
	//reference is an alias to the value
	std::string &stringREF = str;
	stringREF = "dsadsa"; //test
	// "&stringREF" is the memory address of the string reference
	std::cout << "memory address of stringREF: " << &stringREF << std::endl;
	// "stringREF" is the value of the string reference
	std::cout << "value of stringREF         : " << stringREF << std::endl;
	std::cout << "memory address of str      : " << &str << std::endl;
	std::cout << "value of the str           : " << str << std::endl << std::endl;
}
