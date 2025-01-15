/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:14:48 by welow             #+#    #+#             */
/*   Updated: 2025/01/15 21:14:44 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief calculate the area of a triangle
 * @param a Point a
 * @param b Point b
 * @param c Point c
 * @return area of the triangle
 * @note 1. using shoelace formula
 * @note 2. area = (x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2))
 * @note 3. abs() is used to get the absolute value of the area
*/
static Fixed area_of_triangle(Point const a, Point const b, Point const c)
{
	Fixed area = a.getX() * (b.getY() - c.getY())
		+ b.getX() * (c.getY() - a.getY())
		+ c.getX() * (a.getY() - b.getY());
	Fixed abs_area = std::abs(area.toFloat()) / 2;
	return (abs_area);
}

/**
 * @brief check the point is inside the triangle
 * @param a Point a
 * @param b Point b
 * @param c Point c
 * @param p Poinnt for checking
 * @return true if the point is inside the triangle else false if outside
*/
bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed total_area = area_of_triangle(a, b, c);
	Fixed area1 = area_of_triangle(p, a, b);
	Fixed area2 = area_of_triangle(p, b, c);
	Fixed area3 = area_of_triangle(p, a, c);

	if (area1 != 0 && area2 != 0 && area3 != 0 && area1 + area2 + area3 <= total_area)
		return (true);
	return (false);
}