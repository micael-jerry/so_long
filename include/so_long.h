/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:35:10 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/21 06:13:25 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../lib/mlx_linux/mlx.h"
#include "../lib/ft_printf/include/ft_printf.h"

// ERROR
void	put_error(char *msg);

// VALIDATOR
void	map_arg_validator(int argc, char const *argv[]);

#endif
