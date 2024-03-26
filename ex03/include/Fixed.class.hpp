/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:27:00 by nbardavi          #+#    #+#             */
/*   Updated: 2024/03/26 11:59:41 by nbardavi         ###   ########.fr       */
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

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	Fixed operator+( const Fixed& other );
	Fixed operator-( const Fixed& other );
	Fixed operator*( const Fixed& other );
	Fixed operator/( const Fixed& other );

	bool operator>(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
    
	friend std::ostream& operator<<(std::ostream& out, const Fixed& f);
 
	// ************************************************
    // *                Member Functions              *
    // ************************************************
	
	float toFloat(void) const;
	int toInt(void) const;
	int	getRawBits( void ) const;
	void setRawBits(int const raw);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

private:
	int _number;
	static const int _bits;
	static const int _int_bits;
};

#endif
