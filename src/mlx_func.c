/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:25:50 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/26 17:12:16 by mfidimal         ###   ########.fr       */
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
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	free_map_data(data->map_data);
}
