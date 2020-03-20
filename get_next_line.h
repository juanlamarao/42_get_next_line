/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:34:30 by juolivei          #+#    #+#             */
/*   Updated: 2020/03/20 00:52:28 by id_na_int        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

#ifndef OPEN_MAX
# define OPEN_MAX 256
#endif
