/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:48:07 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/29 08:06:46 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data_game(t_data *data)
{
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->road)
		mlx_destroy_image(data->mlx, data->road);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->collectible_obj)
		mlx_destroy_image(data->mlx, data->collectible_obj);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map_data)
		free_map_data(data->map_data);
}

int	exit_game(t_data *data)
{
	free_data_game(data);
	exit(0);
	return (0);
}

int	is_end_of_game(t_data *data)
{
	t_map_coordinate	c_coord;
	t_map_coordinate	t_coord;

	c_coord = find_coordinate_obj(data->map_data->data, data->map_data->heigth,
			data->map_data->width, 'C');
	t_coord = find_coordinate_obj(data->map_data->data, data->map_data->heigth,
			data->map_data->width, 'T');
	if ((c_coord.x == -1 && c_coord.y == -1)
		&& (t_coord.x != -1 && t_coord.y != -1))
		return (1);
	return (0);
}
