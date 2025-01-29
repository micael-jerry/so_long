/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_validator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:04:44 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/29 13:04:11 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_wall(t_map_data *map_data)
{
	int	i;

	i = 0;
	while (i < map_data->width)
	{
		if (map_data->data[0][i] != '1' || map_data->data[map_data->heigth
			- 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map_data->heigth)
	{
		if (map_data->data[i][0] != '1' || map_data->data[i][map_data->width
			- 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int		is_content_other_char(t_map_data *map_data)
{
	int i;
	int j;

	i = 0;
	while (i < map_data->heigth)
	{
		j = 0;
		while (j < map_data->width)
		{
			if (map_data->data[i][j] != '1' && map_data->data[i][j] != '0' && map_data->data[i][j] != 'P' && map_data->data[i][j] != 'C' && map_data->data[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	map_content_validator(t_map_data *map_data)
{
	if (!is_valid_wall(map_data))
		return (free_map_data(map_data),
			put_error("The map is not completely enclosed by walls"));
	if (count_map_obj(map_data, 'E') != 1)
		return (free_map_data(map_data),
			put_error("Number of exits on the map invalid"));
	if (count_map_obj(map_data, 'P') != 1)
		return (free_map_data(map_data),
			put_error("Number of entries on the map invalid"));
	if (count_map_obj(map_data, 'C') < 1)
		return (free_map_data(map_data),
			put_error("Number of collectible object on the map invalid"));
	if (is_content_other_char(map_data))
		return (free_map_data(map_data),
			put_error("Contains another value"));
	accessibility_check(map_data);
}
