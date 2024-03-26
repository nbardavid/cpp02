/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:54:24 by nbardavi          #+#    #+#             */
/*   Updated: 2024/03/20 16:54:51 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
#define COLORS_H

#include <string>

namespace Color {
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
}

#endif
