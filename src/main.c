/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:23:55 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/21 21:37:41 by mfidimal         ###   ########.fr       */
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
	char	**data;

	map_arg_validator(argc, argv);
	fd = get_fd_map(argv[1]);
	data = get_map_data(fd);
	print_matrix(data);
	return (0);
}
