/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:36:43 by welow             #+#    #+#             */
/*   Updated: 2025/02/28 21:00:19 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#ifndef CALL
#define CALL 0
#endif

#include <iostream>
#include <string>

#define GREEN_H "\033[0;42m"
#define RESET "\033[0m"

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal &operator=(const WrongAnimal &src);
		virtual ~WrongAnimal(void);

		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif