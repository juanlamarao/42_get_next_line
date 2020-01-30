/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:20:33 by juolivei          #+#    #+#             */
/*   Updated: 2020/01/29 11:12:05 by juolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strdup(const char *s)
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

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_s;

	if (!s)
		return (NULL);
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

static void	ft_clear(char **file)
{
	if (file && *file)
	{
		free(*file);
		*file = (char *)'\0';
	}
}

static int	ft_local_store(char **file, char **line, int read_ret)
{
	int		size;
	char	*tmp;

	if (read_ret < 0)
		return (-1);
	if (read_ret == 0 && !*file)
		return (0);
	size = 0;
	while ((*file)[size] != '\n' && (*file)[size] != '\0')
		size++;
	if ((*file)[size] == '\n')
	{
		*line = ft_substr(*file, 0, size);
		tmp = ft_strdup(&((*file)[size + 1]));
		free(*file);
		*file = tmp;
		if (!(*file)[0])
			ft_clear(file);
	}
	else
	{
		*line = ft_strdup(*file);
		ft_clear(file);
	}
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
	status_ret = ft_local_store(&file[fd], line, read_ret);
	return (status_ret);
}
