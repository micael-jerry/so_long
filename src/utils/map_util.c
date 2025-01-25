/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:19:59 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/24 18:57:45 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_data(t_map_data *map_data)
{
	if (!map_data)
		return ;
	if (map_data->data)
		ft_matrixfree((void **)map_data->data);
	free(map_data);
}

int	count_map_obj(t_map_data *map_data, char obj)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < map_data->heigth)
	{
		j = 0;
		while (j < map_data->width)
		{
			if (map_data->data[i][j] == obj)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_map_coordinate find_coordinate_obj(char **data, int h, int w, char obj)
{
	t_map_coordinate coordinate;
	int	i;
	int	j;

	coordinate.x = -1;
	coordinate.y = -1;
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (data[i][j] == obj)
			{
				coordinate.x = j;
				coordinate.y = i;
				break ;
			}
			j++;
		}
		
		i++;
	}
	return (coordinate);
}
