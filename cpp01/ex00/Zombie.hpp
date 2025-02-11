/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:58:08 by welow             #+#    #+#             */
/*   Updated: 2025/02/11 14:36:39 by welow            ###   ########.fr       */
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
		Zombie(std::string zombieName);
		~Zombie(void);
		std::string getZombieName(void);
		void announce(void);
};

Zombie  *newZombie(std::string name);
void	randomChump(std::string name);

#endif