/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:31:26 by welow             #+#    #+#             */
/*   Updated: 2024/12/27 18:20:53 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_raw;
		static const int	fractional_bit = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
}

#endif