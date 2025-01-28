/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:35:10 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/28 05:58:35 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#define FRAME_SIZE 32

# include "../lib/ft_printf/include/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/mlx_linux/mlx.h"

typedef struct s_map_data
{
	char			**data;
	int				width;
	int				heigth;
}					t_map_data;

typedef struct s_map_coordinate
{
	int				x;
	int				y;
}					t_map_coordinate;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*collectible_obj;
	void	*player;
	void	*wall;
	void	*road;
	void	*exit;
	t_map_data *map_data;
}	t_data;


// MAP
t_map_data			*get_map_data(char const *filename);
void				map_arg_validator(int argc, char const *argv[]);
void				map_data_validator(t_map_data *map_data);
void				map_content_validator(t_map_data *map_data);
void				accessibility_check(t_map_data *map_data);

// ERROR
void				put_error(char *msg);

// UTILS
void				free_map_data(t_map_data *map_data);
int					count_map_obj(t_map_data *map_data, char obj);
t_map_coordinate	find_coordinate_obj(char **data, int h, int w, char obj);
void				trans_accessible_to_y(char **data, int heigth, int width);
int					have_obj_around(char **data, int x, int y, char c);

// MATRIX
char				**matrix_char_join(char **matrix, char *new);
char				**matrix_cpy(char **matrix);

// MLX FUNC
void	free_data_game(t_data *data);

// TEST
void				print_matrix(char **matrix);
void				print_arr(int *arr);

#endif
