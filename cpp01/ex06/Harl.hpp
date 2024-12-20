/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:28:20 by welow             #+#    #+#             */
/*   Updated: 2024/12/20 20:45:00 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define RESET "\033[0m"


class Harl
{
	private:
		void	_debug();
		void	_info();
		void	_warning();
		void	_error();

	public:
		void	complain( std::string level );
};

#endif
