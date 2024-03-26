/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:24:15 by nbardavi          #+#    #+#             */
/*   Updated: 2024/03/26 13:40:10 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.class.hpp"

int main( void ) {

    std::cout << std::endl << "Tests for limits with int constructor" << std::endl;
    std::cout << Fixed(-8388609) << std::endl;
    std::cout << Fixed(-8388608) << std::endl;
    std::cout << Fixed(8388608) << std::endl;
    std::cout << Fixed(8388607) << std::endl;

    std::cout << std::endl << "Tests for limits with float constructor" << std::endl;
    std::cout << Fixed(-8388609.0f) << std::endl;
    std::cout << Fixed(-8388608.0f) << std::endl;
    std::cout << Fixed(8388608.0f) << std::endl;
    std::cout << Fixed(8388607.0f) << std::endl;

    std::cout <<std::endl << "Tests for multiplication max" << std::endl;
    std::cout << Fixed(2896) * Fixed(2896) << std::endl;
    std::cout << Fixed(2897) * Fixed(2897) << std::endl;

    std::cout <<std::endl << "Tests for division max" << std::endl;
    std::cout << Fixed(1) / Fixed(0.0003f) << std::endl;
    std::cout << Fixed(2500) / Fixed(12) << std::endl;

    std::cout <<std::endl << "Tests for addition max" << std::endl;
    std::cout << Fixed(8388607.0f) + Fixed(10) << std::endl;
    std::cout << Fixed(42) + Fixed(42) << std::endl;

    std::cout <<std::endl << "Tests for soustraction max" << std::endl;
    std::cout << Fixed(-8388607.0f) - Fixed(10) << std::endl;
    std::cout << Fixed(42) - Fixed(43) << std::endl;
    return 0;
}
