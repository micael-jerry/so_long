/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:23:55 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/22 09:38:57 by mfidimal         ###   ########.fr       */
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

int	main(int argc, char const *argv[])
{
	int		fd;
	t_map_data	*map_data;

	map_data = (t_map_data *) malloc(sizeof(t_map_data *));
	map_arg_validator(argc, argv);
	fd = get_fd_map(argv[1]);
	map_data->data = get_matrix_map(fd);
	map_data->heigth = ft_matrixsize((void **)map_data->data);
	map_data->width = ft_strlen(map_data->data[0]);

	map_data_validator(map_data);

	print_matrix(map_data->data);
	return (0);
}
