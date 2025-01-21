/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:16:13 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/21 19:17:23 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen_gnl(char const *str);
char	*ft_strchr_gnl(char const *str, int c);
char	*ft_strdup_gnl(char const *src);
void	*ft_calloc_gnl(size_t count, size_t size);
char	*strjoin_free(char *s1, const char *s2);
char	*get_next_line(int fd);

#endif
