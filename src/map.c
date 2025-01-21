/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:47:31 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/21 22:08:00 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_matrix_map(int fd)
{
	char	**data;
	char	*line;

	data = NULL;
	line = get_next_line(fd);
	while (line)
	{
		data = matrix_char_join(data, line);
		line = get_next_line(fd);
	}
	return (data);
}
