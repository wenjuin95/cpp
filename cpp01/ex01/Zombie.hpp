/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:03:59 by welow             #+#    #+#             */
/*   Updated: 2025/02/11 14:37:56 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string _zombieName;
	public:
		Zombie(void);
		~Zombie(void);
		void		setZombieName(std::string name);
		std::string	getZombieName(void);
		void		announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif