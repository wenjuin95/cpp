/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:40:59 by welow             #+#    #+#             */
/*   Updated: 2024/11/15 15:39:47 by welow            ###   ########.fr       */
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
	std::string *stringPTR = &str;
	// "stringPTR" is the memory address of the string pointer
	std::cout << "memory address of stringPTR: " << stringPTR << std::endl;
	// "*stringPTR" is the value of the string pointer
	std::cout << "value of the stringPTR     : " << *stringPTR << std::endl << std::endl;

	// "stringREF" is a reference to the string
	std::string &stringREF = str;
	// "&stringREF" is the memory address of the string reference
	std::cout << "memory address of stringREF: " << &stringREF << std::endl;
	// "stringREF" is the value of the string reference
	std::cout << "value of stringREF         : " << stringREF << std::endl;
}
