/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:34:41 by welow             #+#    #+#             */
/*   Updated: 2025/02/07 20:35:08 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

#define YELLOW_H "\033[43m"
#define RESET "\033[0m"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		~Dog(void);
		void makeSound(void) const;
};

#endif