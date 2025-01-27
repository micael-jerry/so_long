/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:25:50 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/27 18:43:07 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data_game(t_data *data)
{
	if (data->collectible_obj)
		mlx_destroy_image(data->mlx, data->collectible_obj);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->road)
		mlx_destroy_image(data->mlx, data->road);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		free(data->mlx);
	if (data->map_data)
		free_map_data(data->map_data);
}
