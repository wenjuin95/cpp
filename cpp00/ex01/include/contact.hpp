/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contract.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:57:37 by welow             #+#    #+#             */
/*   Updated: 2024/05/26 17:57:37 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

/*
* class: smilar to struct in c
*
* important for default constructor:
* 1. Initialization: This avoids any undefined or unexpected state.
* 2. Consistency: Ensures that every Car object starts in a consistent and 
*	 predictable state, improving code reliability and readability.
* 3. Safety: Helps prevent bugs related to uninitialized member variables, 
*	 especially for built-in types like int, where uninitialized variables 
*	 can lead to undefined behavior.
*
*/

//Contact :: get contact information
/*
* 1. first & last name
* 2. nickname
* 3. phone number
* 4. dark secret is a secret word (optional)
*/
class Contact
{
	private
		std::string first_name;
		std::string last_name;
		std::string	nickname;
		std::string	dark_secret;
		int			phone_number;
	public:
		Contact();
		~Contact();
};

#endif