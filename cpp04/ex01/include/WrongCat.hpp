/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:35:51 by welow             #+#    #+#             */
/*   Updated: 2025/02/07 20:40:19 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

#define PURPLE_H "\033[45m"
#define RESET "\033[0m"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(std::string type);
		WrongCat(const WrongCat &src);
		WrongCat &operator=(const WrongCat &src);
		~WrongCat(void);
		void makeSound(void) const;
};

#endif