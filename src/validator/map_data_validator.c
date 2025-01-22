/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:21:34 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/22 11:26:07 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int is_rectangle(t_map_data *map_data)
{
	if (map_data->heigth >= map_data->width)
		return (0);
	return (1);
}

static int is_same_len(t_map_data *map_data)
{
	int i;

	i = 0;
	while (i < map_data->heigth)
	{
		if ((int) ft_strlen(map_data->data[i]) != map_data->width)
			return (0);
		i++;
	}
	return (1);
}

void	map_data_validator(t_map_data *map_data)
{
	if (!map_data->data)
		return (free_map_data(map_data), put_error("Empty"));
	if (!is_rectangle(map_data))
		return (free_map_data(map_data), put_error("The map is not rectangular"));
	if (!is_same_len(map_data))
		return (free_map_data(map_data), put_error("Some line have not same length"));
}
