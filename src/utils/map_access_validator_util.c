/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_access_validator_util.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:33:23 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/25 10:56:28 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int is_valid_to_trans(char c)
{
	if (c == '0' || c == 'C')
		return (1);
	return (0);
}

static void transform_around_to_Z(char **data, int x, int y)
{
	if (is_valid_to_trans(data[y-1][x-1]))
		data[y-1][x-1] = 'Z';
	if (is_valid_to_trans(data[y-1][x]))
		data[y-1][x] = 'Z';
	if (is_valid_to_trans(data[y-1][x+1]))
		data[y-1][x+1] = 'Z';
	if (is_valid_to_trans(data[y][x-1]))
		data[y][x-1] = 'Z';
	if (is_valid_to_trans(data[y][x+1]))
		data[y][x+1] = 'Z';
	if (is_valid_to_trans(data[y+1][x-1]))
		data[y+1][x-1] = 'Z';
	if (is_valid_to_trans(data[y+1][x]))
		data[y+1][x] = 'Z';
	if (is_valid_to_trans(data[y+1][x+1]))
		data[y+1][x+1] = 'Z';
}

void trans_accessible_to_Y(char **data, int heigth, int width)
{
	t_map_coordinate entry;
	int y;
	int x;

	entry = find_coordinate_obj(data, heigth, width, 'P');
	transform_around_to_Z(data, entry.x, entry.y);
	y = 0;
	while (y < heigth)
	{
		x = 0;
		while (x < width)
		{
			if (data[y][x] == 'Z')
			{
				data[y][x] = 'Y';
				transform_around_to_Z(data, x, y);
				y = 0, x = 0;
			}
			x++;
		}
		y++;
	}
}

int	have_obj_around(char **data, int x, int y, char c)
{
	if (data[y-1][x-1] == c)
		return (1);
	if (data[y-1][x] == c)
		return (1);
	if (data[y-1][x+1] == c)
		return (1);
	if (data[y][x-1] == c)
		return (1);
	if (data[y][x+1] == c)
		return (1);
	if (data[y+1][x-1] == c)
		return (1);
	if (data[y+1][x] == c)
		return (1);
	if (data[y+1][x+1] == c)
		return (1);
	return (0);
}
