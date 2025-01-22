/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:21:34 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/22 09:44:13 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int is_rectangle(t_map_data *map_data)
{
	if (map_data->heigth >= map_data->width)
	{
		ft_matrixfree((void **) map_data->data);
		return (0);
	}
	return (1);
}

void	map_data_validator(t_map_data *map_data)
{
	if (!is_rectangle(map_data))
		return (free(map_data), put_error("The map is not rectangular"));
}
