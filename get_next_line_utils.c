/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:37:12 by juolivei          #+#    #+#             */
/*   Updated: 2020/01/30 20:41:18 by juolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_and_return_null(char *s)
{
	free(s);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t char_count;

	char_count = 0;
	while (str[char_count] != '\0')
	{
		char_count++;
	}
	return (char_count);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dstcpy;
	char	*srccpy;
	int		i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dstcpy = (char*)dst;
	srccpy = (char*)src;
	if (dst < src)
		while (i < (int)len)
		{
			dstcpy[i] = srccpy[i];
			i++;
		}
	else
	{
		i = (int)len;
		while (i != 0)
		{
			dstcpy[i - 1] = srccpy[i - 1];
			i--;
		}
	}
	return (dstcpy);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	int		i;
	char	*tmp;

	size = 0;
	i = 0;
	size = ft_strlen(s1);
	tmp = malloc(sizeof(char) * size + 1);
	if (tmp == NULL)
		return (NULL);
	while (i < size)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
