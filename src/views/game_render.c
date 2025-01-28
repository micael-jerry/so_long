/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 06:23:36 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/28 13:51:42 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void frame_render(t_data *data, int x, int y)
{
	char element;

	element = data->map_data->data[y][x];

	if (element == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, x * FRAME_SIZE, y * FRAME_SIZE);
	if (element == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->road, x * FRAME_SIZE, y * FRAME_SIZE);
	if (element == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, x * FRAME_SIZE, y * FRAME_SIZE);
	if (element == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit, x * FRAME_SIZE, y * FRAME_SIZE);
	if (element == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->collectible_obj, x * FRAME_SIZE, y * FRAME_SIZE);
}

int		game_render(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->map_data->heigth)
	{
		x = 0;
		while (x < data->map_data->width)
		{
			frame_render(data, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
