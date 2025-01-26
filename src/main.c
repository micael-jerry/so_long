/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:23:55 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/26 07:01:11 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_fd_map(char const *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		put_error("Error on read file");
	return (fd);
}

static t_map_data	*get_map_data(int fd)
{
	t_map_data	*map_data;

	map_data = (t_map_data *)malloc(sizeof(t_map_data));
	if (!map_data)
		return (NULL);
	map_data->data = get_matrix_map(fd);
	if (map_data->data)
	{
		map_data->heigth = ft_matrixsize((void **)map_data->data);
		map_data->width = ft_strlen(map_data->data[0]);
		return (map_data);
	}
	return (free_map_data(map_data), put_error("Empty file"), NULL);
}

int	main(int argc, char const *argv[])
{
	int			fd;
	t_map_data	*map_data;

	map_arg_validator(argc, argv);
	fd = get_fd_map(argv[1]);
	map_data = get_map_data(fd);
	map_data_validator(map_data);
	map_content_validator(map_data);

	t_data img;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Game");
	img.img = mlx_new_image(mlx, 1920,1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	put_pixel(&img, 200, 200, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);

	return (free_map_data(map_data), 0);
}
