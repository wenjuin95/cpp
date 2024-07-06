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
		Phonebook(void); //default constructor
		~Phonebook(void); //default destructor
		void AddContact(void);
		void SearchContact(void);
		bool GetContactDetail(Contact t_contact);
		void DisplayContactList(void);
		void ReturnContact(int index);
};

std::string	get_input(std::string message, bool HandleDigit);
std::string	ft_truncated(std::string str);
bool		CheckInput(std::string input);
bool		CheckDigit(std::string str);

#endif