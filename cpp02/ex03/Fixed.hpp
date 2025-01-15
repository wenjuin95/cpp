/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:22:35 by welow             #+#    #+#             */
/*   Updated: 2025/01/15 14:13:15 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

# define CALL 0

class Fixed
{
	private:
		int					_raw;
		static const int	_bit = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed(void);
		Fixed(int const nb);
		Fixed(float const nb);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(Fixed const &src) const;
		bool	operator<(Fixed const &src) const;
		bool	operator>=(Fixed const &src) const;
		bool	operator<=(Fixed const &src) const;
		bool	operator==(Fixed const &src) const;
		bool	operator!=(Fixed const &src) const;

		Fixed	operator+(Fixed const &src) const;
		Fixed	operator-(Fixed const &src) const;
		Fixed	operator*(Fixed const &src) const;
		Fixed	operator/(Fixed const &src) const;

		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		static Fixed 		&min( Fixed &a, Fixed &b );
		static Fixed const	&min( Fixed const &a, Fixed const &b );
		static Fixed		&max( Fixed &a, Fixed &b );
		static Fixed const	&max( Fixed const &a, Fixed const &b );
};

std::ostream &operator<<(std::ostream &output, Fixed const &src);

#endif