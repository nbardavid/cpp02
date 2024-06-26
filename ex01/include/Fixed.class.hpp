/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:27:00 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/23 15:35:53 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include<iostream>
class Fixed {
public:

	// ************************************************
	// *                Constructors                  *
	// ************************************************
	
	Fixed(const Fixed& other);
	Fixed(int const num);
	Fixed(float const num);
	Fixed();

	// ************************************************
	// *                Destructors                   *
	// ************************************************
	
	~Fixed(); 
	
	// ************************************************
	// *                Operator Overloads            *
	// ************************************************

	Fixed& operator=(const Fixed& other);
 
	// ************************************************
    // *                Member Functions              *
    // ************************************************
	
	float toFloat(void) const;
	int toInt(void) const;
	int	getRawBits( void ) const;
	void setRawBits(int const raw);

private:
	int number;
	static const int bits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);
#endif
