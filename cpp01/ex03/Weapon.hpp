/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:52:07 by welow             #+#    #+#             */
/*   Updated: 2025/02/11 14:40:49 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

#define RED_H "\033[0;41m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(std::string type);
		~Weapon(void);
		void		setType(std::string type);
		// "const reference" is to get the value of the object without changing it
		std::string const	&getType(void) const;
};

#endif
