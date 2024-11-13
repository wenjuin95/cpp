/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:40:59 by welow             #+#    #+#             */
/*   Updated: 2024/11/13 15:58:11 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{

	std::string str = "HI THIS IS BRAIN";
	std::cout << "memory address of str      : " << &str << std::endl;
	std::cout << "value of the str           : " << str << std::endl << std::endl;

	std::string *stringPTR = &str;
	std::cout << "memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "value of the stringPTR     : " << *stringPTR << std::endl << std::endl;

	std::string &stringREF = str;
	std::cout << "memory address of stringREF: " << &stringREF << std::endl;
	std::cout << "value of stringREF         : " << stringREF << std::endl;
}
