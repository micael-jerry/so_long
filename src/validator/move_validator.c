/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:41:12 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/29 07:41:42 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(t_map_coordinate new_p_coord, t_data *data)
{
	if (data->map_data->data[new_p_coord.y][new_p_coord.x] == '0')
		return (1);
	if (data->map_data->data[new_p_coord.y][new_p_coord.x] == 'C')
		return (1);
	if (data->map_data->data[new_p_coord.y][new_p_coord.x] == 'E')
		return (1);
	if (data->map_data->data[new_p_coord.y][new_p_coord.x] == 'T')
		return (1);
	return (0);
}
