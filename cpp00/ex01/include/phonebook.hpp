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
	public:
		Phonebook(void);
		int index;
		void AddContact(void);
		void SearchContact(void);
		bool set_contact_detail(Contact &t_contact);
		void DisplayContactList(void);
		void get_detail(int index);
};

std::string	ft_truncated(std::string str);
bool		check_back_or_exit(std::string input);
bool		check_and_set_input(std::string input, Contact &t_contact,
			bool(Contact::*func)(std::string));

#endif