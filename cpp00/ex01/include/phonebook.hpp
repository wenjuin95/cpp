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

#include "includelib.hpp"
#include "contact.hpp"

# define RED "\033[0;31m"
# define GREEN "\033[1;42m"
# define YELLOW "\033[1;43m"
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
		Contact _contact[8]; //array of contact
		int _index; //index of the contact
		// void backdoor(void); //show purpose
	public:
		void add_contact(void);
		void search_contact(void);
};

std::string	get_input(std::string message, int is_alpha);
std::string	ft_truncated(std::string str);
void 		CheckExitOrReturn(std::string input);
int			check_alpha(std::string str);
int			check_digit(std::string str);

#endif