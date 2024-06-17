/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:39:32 by welow             #+#    #+#             */
/*   Updated: 2024/06/01 18:39:32 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream> //input and output
#include <iomanip> // std::setw :: set width of the next input/output field
#include <cstdio> //for "stdin"
#include "contact.hpp"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
# define TRUE 1
# define FALSE 0

/*
*	phonebook class consist of:
*	1. contact information
*	2. add contact
*	3. search contact
*	4. display contact
*/
class Phonebook
{
	private:
		Contact _contact[8];
		int _index;
		// void backdoor(void); //show purpose
	public:
		Phonebook(void);
		~Phonebook(void);
		void add_contact(void);
		void search_contact(void);
		void display_contact(void); //show purpose
};

std::string	get_input(std::string message, int is_alpha);
int			check_alpha(std::string str);
int			check_digit(std::string str);

#endif