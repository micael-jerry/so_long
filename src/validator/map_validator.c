/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 05:52:07 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/21 06:12:57 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_map_file_name(const char *map_file_name)
{
	size_t len;

	len = ft_strlen(map_file_name);
	if (len < 5)
		return (0);
	if (ft_strncmp(".ber", &map_file_name[len - 4], 4) != 0)
		return (0);
	return (1);
}

void	map_arg_validator(int argc, char const *argv[])
{
	if (argc == 1)
		put_error("No arg");
	if (argc > 2)
		put_error("Many args");
	if (!is_valid_map_file_name(argv[1]))
		put_error("Invalid map file name");
}
