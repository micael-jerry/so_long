/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:23:54 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/24 18:34:14 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**matrix_char_join(char **matrix, char *new)
{
	char	**res;
	int		i;
	char	*end_line;

	i = 0;
	res = (char **)malloc((ft_matrixsize((void **)matrix) + 2)
			* sizeof(char *));
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

char	**matrix_cpy(char **matrix)
{
		int i;
		char **m_cpy;
		int matrix_len;

		matrix_len = ft_matrixsize((void **) matrix);
		m_cpy = (char **) malloc(matrix_len * sizeof(char *));
		if (!m_cpy)
			return NULL;
		i = 0;
		
		while (i < matrix_len)
		{
			m_cpy[i] = ft_strdup(matrix[i]);
			i++;
		}
		return (m_cpy);
}
