/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:34:43 by nbardavi          #+#    #+#             */
/*   Updated: 2024/03/27 11:02:30 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_CLASS_HPP
# define POINT_CLASS_HPP

#include "Fixed.class.hpp"

class Point {
public:

	// ************************************************
	// *                 Constructors                 *
	// ************************************************

	Point();
	Point(const float& nb1, const float& nb2);
	Point(const Point& other);

	Point &operator=(Point &);
	Point &operator=(const Point &);
	~Point();

	const Fixed getX() const;
	const Fixed getY() const;

private:
	const Fixed _x;
	const Fixed _y;
};

#endif
