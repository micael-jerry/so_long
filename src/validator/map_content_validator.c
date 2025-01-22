/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_validator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:04:44 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/22 16:33:30 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int is_valid_wall(t_map_data *map_data)
{
	int i;

	i = 0;
	while (i < map_data->width)
	{
		if (map_data->data[0][i] != '1' || map_data->data[map_data->heigth - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map_data->heigth)
	{
		if (map_data->data[i][0] != '1' || map_data->data[i][map_data->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	map_content_validator(t_map_data *map_data)
{
	if (!is_valid_wall(map_data))
		return (free_map_data(map_data), put_error("The map is not completely enclosed by walls"));
}
