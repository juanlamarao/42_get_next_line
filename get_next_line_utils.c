/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:18:02 by juolivei          #+#    #+#             */
/*   Updated: 2020/01/29 09:41:08 by juolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int number;

	number = 0;
	while (src[number] != '\0')
	{
		dest[number] = ((char *)src)[number];
		number++;
	}
	dest[number] = ((char *)src)[number];
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	int sizedest;
	int sizesrc;
	int total;
	int nsrc;

	sizesrc = ft_strlen(src);
	sizedest = ft_strlen(dest);
	total = sizesrc + sizedest;
	nsrc = 0;
	while (sizedest < total)
	{
		dest[sizedest] = ((char *)src)[nsrc];
		sizedest++;
		nsrc++;
	}
	dest[sizedest] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		full_len;
	char	*new_str;

	full_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new_str = (char *)malloc((full_len + 1) * sizeof(*s1))))
		return (NULL);
	ft_strcpy(new_str, s1);
	ft_strcat(new_str, s2);
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
