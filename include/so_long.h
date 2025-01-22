/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:35:10 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/22 09:27:43 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../lib/mlx_linux/mlx.h"
#include "../lib/ft_printf/include/ft_printf.h"
#include "../lib/get_next_line/get_next_line.h"

typedef struct s_map_data
{
	char **data;
	int width;
	int heigth;
} t_map_data;

// ERROR
void	put_error(char *msg);

// MAP
void	map_arg_validator(int argc, char const *argv[]);
char 	**get_matrix_map(int fd);
void	map_data_validator(t_map_data *map_data);

// MATRIX
char	**matrix_char_join(char **matrix, char *new);

// TEST
void	print_matrix(char **matrix);
void    print_arr(int *arr);

#endif
