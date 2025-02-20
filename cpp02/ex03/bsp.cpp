/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:14:48 by welow             #+#    #+#             */
/*   Updated: 2025/02/20 21:23:30 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/

/**
 * @brief check if point is on a line
 * @param a Point a
 * @param b Point b
 * @param p Point p
 * @return true if point is on the line, false otherwise
 * @note 1. using equation of a line in a slope-intercept form
 * @note 2. formula for this is y = mx + c
 * @note 2. m = (y2 - y1) / (x2 - x1)
 * @note 3. c = y - mx
*/
static bool	point_is_on_line(Point const a, Point const b, Point const p)
{
	Fixed m, c, res;

	m = ((b.getX() - a.getX()) / (b.getY() - a.getY()));
	c = a.getY() - m * a.getX();
	res = m * p.getX() + c;
	if (res == p.getY())
		return (true);
	else
		return (false);
}

/**
 * @brief calculate the area of a triangle
 * @param a Point a
 * @param b Point b
 * @param c Point c
 * @return area of the triangle
 * @note 1. using shoelace formula
 * @note 2. area = (x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)) / 2
 * @note 3. abs() is used to get the absolute value of the area to avoid negative value
*/
static float get_area(Point const a, Point const b, Point const c)
{
	float area;
	area = ((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()))
		+ (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()))
		+ (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2;
	return (std::abs(area));
}

bool bsp( Point const a, Point const b, Point const c, Point const p )
{
	float total_area, pab, pbc, pac;

	total_area = get_area(a, b, c);
	pab = get_area(p, a, b);
	pbc = get_area(p, b, c);
	pac = get_area(p, a, c);
	if (point_is_on_line(a, b, p) || point_is_on_line(b, c, p) || point_is_on_line(a, c, p))
		return (false);
	if (total_area == pab + pbc + pac)
		return (true);
	else
		return (false);
}
