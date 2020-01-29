/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remover.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:52:30 by juolivei          #+#    #+#             */
/*   Updated: 2020/01/26 12:48:44 by juolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

# define BUF_SIZE 1

void	read_loop_and_print(fd)
{
	char full_file[5][100];
	char buffer[BUF_SIZE + 1];
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = 0;
	printf("\n\nLOOPING\n");
	while (ret = read(fd, buffer, BUF_SIZE))
	{
		buffer[ret] = '\0';
		while (buffer[n])
		{
			if (buffer[n] != '\n')
			{
				full_file[j][i] = buffer[n];
				i++;
			}
			else
			{
				full_file[j][i] = '\0';
				j++;
				i = 0;
			}
			n++;
		}
		n = 0;
	}
	printf("%s\n", full_file[0]);
	printf("%s\n", full_file[1]);
	printf("%s\n", full_file[2]);
	printf("%s\n", full_file[3]);
	printf("\n");
}


int		main(int argc, char **argv)
{
	int fd;
	int r_ret;
	char str[BUF_SIZE + 1];

	if (argc == 1)
	{
		printf("Passe como parametro o nome/caminho do arquivo a ser aberto!\n");
		return (1);
	}

	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		printf("Não conseguiu abriu o arquivo\n");
		return (1);
	}
	read_loop_and_print(fd);
	r_ret = read(fd, str, BUF_SIZE);
	str[r_ret] = '\0';
	printf("### texto ###\n%s\n", str);
	printf("nº de bytes lidos: %d\n", r_ret);
	if ((fd = close(fd)) < 0)
	{
		printf("Não conseguiu fechar o arquivo!\n");
		return (1);
	}
	printf("Funcionou!\n");
	return (0);
}
