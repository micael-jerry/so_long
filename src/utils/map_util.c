/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:19:59 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/22 11:21:56 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_data(t_map_data *map_data)
{
	if (!map_data)
		return ;
	if (map_data->data)
		ft_matrixfree((void **) map_data->data);
	free(map_data);
}
