/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_accessibility_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:36:04 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/25 12:43:51 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_exit_accessible(char **data, int heigth, int width)
{
	t_map_coordinate	exit_coordinate;

	exit_coordinate = find_coordinate_obj(data, heigth, width, 'E');
	if (have_obj_around(data, exit_coordinate.x, exit_coordinate.y, 'Y'))
		return (1);
	return (0);
}

static int	are_all_collectible_accessible(char **data, int heigth, int width)
{
	t_map_coordinate	first_collectible;

	first_collectible = find_coordinate_obj(data, heigth, width, 'C');
	if (first_collectible.x == -1 && first_collectible.y == -1)
		return (1);
	return (0);
}

void	accessibility_check(t_map_data *map_data)
{
	char	**data_cp;

	data_cp = matrix_cpy(map_data->data);
	trans_accessible_to_y(data_cp, map_data->heigth, map_data->width);
	if (!is_exit_accessible(data_cp, map_data->heigth, map_data->width))
		return (free_map_data(map_data), ft_matrixfree((void **)data_cp),
			put_error("The exit is not accessible"));
	if (!are_all_collectible_accessible(data_cp, map_data->heigth,
			map_data->width))
		return (free_map_data(map_data), ft_matrixfree((void **)data_cp),
			put_error("Not all collectors items are accessible"));
}
