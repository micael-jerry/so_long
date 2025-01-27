/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:23:55 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/27 18:50:39 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init(t_data *data)
{
	int	w;
	int	h;

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "so_long");
	data->collectible_obj = mlx_xpm_file_to_image(data->mlx, "assets/eggs.xpm", &w, &h);
	data->wall = mlx_xpm_file_to_image(data->mlx, "assets/water.xpm", &w, &h);
	data->player = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm", &w, &h);
	data->exit = mlx_xpm_file_to_image(data->mlx, "assets/house.xpm", &w, &h);
	data->road = mlx_xpm_file_to_image(data->mlx, "assets/path.xpm", &w, &h);

	if (!data->collectible_obj || !data->wall || !data->player || !data->road || !data->exit)
		return (free_data_game(data), put_error("Error during image change"));
}

int	main(int argc, char const *argv[])
{
	t_data data;

	map_arg_validator(argc, argv);
	data.map_data = get_map_data(argv[1]);
	map_data_validator(data.map_data);
	map_content_validator(data.map_data);

	init(&data);
	// mlx_loop(data.mlx);

	print_matrix(data.map_data->data);

	return (free_data_game(&data), 0);
}
