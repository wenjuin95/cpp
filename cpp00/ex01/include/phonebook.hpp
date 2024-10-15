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
*	@brief class Phonebook
*	@note 1. class Phonebook is a class that store the contact
*	@note 2. class Phonebook have the following function:
*		- AddContact: add the contact to the phonebook
*		- SearchContact: search the contact in the phonebook
*		- GetContactDetail: get the contact detail from the input
*		- DisplayContactList: display the contact list
*		- ReturnContact: return the contact detail
*/
/*
*	private: only able to access within the class not outside the class
*	EXAMPLE: _contact only able to access by "AddContact", "SearchContact"
*	         and "ReturnContact" function
*	public: able to access from outside the class and within the class
*	EXAMPLE: "AddContact" and "SearchContact" use in main.cpp
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
		void AddContact(void);
		void SearchContact(void);
		bool GetContactDetail(Contact &t_contact);
		void DisplayContactList(void);
		void ReturnContact(int index);
};

std::string	get_input(std::string message, bool HandleDigit);
std::string	ft_truncated(std::string str);
bool		CheckInput(std::string input);
bool		CheckDigit(std::string str);

#endif