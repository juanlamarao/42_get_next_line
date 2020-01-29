/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:20:33 by juolivei          #+#    #+#             */
/*   Updated: 2020/01/28 19:30:33 by juolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/*
int	ft_strlen(const char *s)
{
	int count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}
*/
char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*new_s;

	s_len = ft_strlen(s);
	if (!(new_s = malloc((s_len + 1) * sizeof(char))))
		return (NULL);
	while (s_len >= 0)
	{
		new_s[s_len] = (char)s[s_len];
		s_len--;
	}
	return (new_s);
}
/*
void	*ft_memset(void *b, int c, size_t len)
{
	char *begin;

	begin = b;
	while (len > 0)
	{
		*begin = c;
		begin++;
		len--;
	}
	return (b);
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	full_size;

	full_size = nmemb * size;
	if (!(ptr = malloc(full_size)))
		return (NULL);
	ft_memset(ptr, 0, full_size);
	return (ptr);
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
}*/

static int	ft_count_until(char *str, const char c)
{
	int	index;

	index = 0;
	while (str[index] != c)
		index++;
	return (index);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_s;

	i = 0;
	if (!(sub_s = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (sub_s);
	sub_s[len] = '\0';
	while (i < len)
	{
		sub_s[i] = ((char *)s)[start];
		i++;
		start++;
	}
	return (sub_s);
}
/*
static void	ft_strncpy(char *d, const char *s, int n)
{
	int	index;

	index = 0;
	while (index < n)
	{
		d[index] = s[index];
		index++;
	}
	d[index] = '\0';
}

static int	ft_status(int read_ret, int fd, char *file)
{
	if (read_ret < 0)
		return (-1);
	else if (read_ret == 0 && !file)
	{
		return (0);
	}
	return (1);
}*/

static int	ft_local_store(char **file, char **line, int fd, int read_ret)
{
	int		i;
	int		len;
	int		cut;
	char	*tmp;

//	len = ft_strlen(file[fd]);
	len = 0;
	while (file[fd][len])
		len++;
	cut = ft_count_until(file[fd], '\n');
	tmp = ft_substr(file[fd], cut + 1, len - (cut + 1));
	while (i < cut)
	{
		line[0][i] = file[fd][i];
		i++;
	}
	line[0][i] = '\0';
	free(file[fd]);
	file[fd] = tmp;
	if (read_ret < 0)
		return (-1);
	else if (read_ret == 0 && !file[fd])
		return (0);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	int			read_ret;
	int			status_ret;
	char		*tmp;
	static char	*file[20];
	char		buffer[BUFFER_SIZE + 1];

	if ((fd < 0) || (line == NULL))
		return (-1);
	while ((read_ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_ret] = '\0';
		if (!file[fd])
			file[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(file[fd], buffer);
			free(file[fd]);
			file[fd] = tmp;
		}
		if (ft_strchr(file[fd], '\n'))
			break ;
	}
	status_ret = ft_local_store(file, line, fd, read_ret);
//	status_ret = ft_status(read_ret, fd, file[fd]);
	return (status_ret);
}
