/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:23:55 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/26 09:51:17 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const *argv[])
{
	t_data data;

	map_arg_validator(argc, argv);
	data.map_data = get_map_data(argv[1]);
	map_data_validator(data.map_data);
	map_content_validator(data.map_data);

	print_matrix(data.map_data->data);

	return (free_map_data(data.map_data), 0);
}
