/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:03:14 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/21 21:50:32 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_matrix(char **matrix)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ft_matrixsize((void **)matrix))
	{
		j = 0;
		while (j < ft_strlen(matrix[i]))
		{
			ft_printf("%c", matrix[i][j]);
			j++;
		}
		i++;
		ft_printf("\n");
	}
}

void	print_arr(int *arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
}
