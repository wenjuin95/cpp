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
* class: smilar to strcut in c
* constructor: function called when an object is created
* destructor: function called when an object is deleted
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