/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:23:54 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/22 11:54:51 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**matrix_char_join(char **matrix, char *new)
{
	char	**res;
	int		i;
	char	*end_line;

	i = 0;
	res = (char **)malloc((ft_matrixsize((void **)matrix) + 2) * sizeof(char *));
	if (!res)
		return (NULL);
	if (matrix)
	{
		while (matrix[i])
		{
			res[i] = ft_strdup(matrix[i]);
			end_line = ft_strchr(res[i], '\n');
			if (end_line)
				*end_line = '\0';
			i++;
		}
		ft_matrixfree((void **)matrix);
	}
	res[i] = new;
	i++;
	res[i] = NULL;
	return (res);
}
