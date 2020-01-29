/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:20:33 by juolivei          #+#    #+#             */
/*   Updated: 2020/01/28 20:04:57 by juolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//verificar questão de multiplus arquivos
//verificar questão de memoria quando ultrapassa o numero de linhas
//verificar algo a mais..

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

static int	ft_count_until(char *str, const char c)
{
	int	index;

	index = 0;
	while (str[index] != c)
		index++;
	return (index);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
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

static int	ft_local_store(char **file, char **line, int fd, int read_ret)
{
	int		i;
	int		len;
	int		cut;
	char	*tmp;

	i = 0;
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
	return (status_ret);
}
