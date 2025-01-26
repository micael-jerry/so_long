/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:23:55 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/26 09:43:04 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const *argv[])
{
	t_map_data	*map_data;

	map_arg_validator(argc, argv);
	map_data = get_map_data(argv[1]);
	map_data_validator(map_data);
	map_content_validator(map_data);

	t_data data;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Game");
	data.img = mlx_new_image(mlx, 1920,1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	put_pixel(&data, 200, 200, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);

	mlx_loop(mlx);

	return (free_map_data(map_data), 0);
}
