/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:27:00 by nbardavi          #+#    #+#             */
/*   Updated: 2024/03/25 13:28:16 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

class Fixed {
public:
	Fixed(const Fixed& other);
	Fixed();
	~Fixed(); 
	Fixed& operator=(const Fixed& other);
	int	getRawBits( void ) const;
	void setRawBits(int const raw);

private:
	int number;
	static const int bits;
};

#endif
