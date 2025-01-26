/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:23:55 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/26 10:09:22 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "so_long");
}

int	main(int argc, char const *argv[])
{
	t_data data;

	map_arg_validator(argc, argv);
	data.map_data = get_map_data(argv[1]);
	map_data_validator(data.map_data);
	map_content_validator(data.map_data);

	init(&data);
	mlx_loop(data.mlx);

	print_matrix(data.map_data->data);

	return (free_map_data(data.map_data), 0);
}
