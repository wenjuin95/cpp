/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:29:23 by welow             #+#    #+#             */
/*   Updated: 2025/02/13 13:42:22 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#define RED_H "\033[1;41m"
#define RESET "\033[0m"

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		~Cat(void);
		void makeSound(void) const;
		const std::string &getIdea(int index) const;
		void setIdea(int index, std::string idea);
		void compareBoth(const Cat &other) const;
};

#endif
