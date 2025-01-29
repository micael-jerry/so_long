/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:47:31 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/26 09:21:51 by mfidimal         ###   ########.fr       */
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

static char	**get_matrix_map(int fd)
{
	char	**data;
	char	*line;

	data = NULL;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		data = matrix_char_join(data, line);
		line = get_next_line(fd);
	}
	return (data);
}

t_map_data	*get_map_data(char const *filename)
{
	int			fd;
	t_map_data	*map_data;

	fd = get_fd_map(filename);
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
