/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:03:55 by juolivei          #+#    #+#             */
/*   Updated: 2020/01/31 12:58:02 by juolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*n_str;

	i = 0;
	j = 0;
	if (!(n_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		n_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		n_str[i++] = s2[j++];
	n_str[i] = '\0';
	free(s1);
	return (n_str);
}

static int	new(char **line, char *buffer)
{
	char	*new;

	new = buffer;
	while (*new)
	{
		if (*new == '\n')
			break ;
		new++;
	}
	if (*new != '\n')
		new = NULL;
	if (new == NULL)
		return (0);
	*new = '\0';
	*line = ft_strjoin(*line, buffer);
	if (*line == NULL)
		return (2);
	*new = '\n';
	ft_memmove(buffer, new, ft_strlen(new));
	buffer[ft_strlen(new)] = '\0';
	return (1);
}

static int	ft_readcycle(int fd, char **line, char *buffer)
{
	int		read_ret;
	int		have_line;

	read_ret = 1;
	while ((read_ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_ret] = '\0';
		have_line = new(line, buffer);
		if (have_line)
			if (have_line > 1)
				return (-1);
			else
				return (1);
		else
		{
			*line = ft_strjoin(*line, buffer);
			if (!(*line))
				return (-1);
		}
	}
	if (read_ret < 0)
		return (-1);
	return (read_ret == 0 ? 0 : 1);
}

static int	ft_checkbuffer(char **line, char *buffer, int *read_ret)
{
	int		i;
	char	*tmp;

	tmp = buffer;
	tmp++;
	i = ft_strlen(tmp);
	ft_memmove(buffer, tmp, i);
	buffer[i] = '\0';
	i = new(line, buffer);
	if (i > 0)
	{
		if (i == 2)
			*read_ret = -1;
		else
			*read_ret = 1;
	}
	else
	{
		if (!(*line = ft_strjoin(*line, buffer)))
			return (-1);
		return (0);
	}
	*read_ret = 1;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	int			flag;
	int			read_ret;
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || !line || fd > OPEN_MAX ||\
			read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!(*line = ft_strdup("")))
		return (-1);
	flag = 0;
	if (buffer[fd][0] == '\n')
		flag = ft_checkbuffer(line, buffer[fd], &read_ret);
	if (!flag)
		read_ret = ft_readcycle(fd, line, buffer[fd]);
	return (read_ret);
}
