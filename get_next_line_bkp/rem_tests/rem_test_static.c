
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

void	static_test(int i)
{
	static int nbr = 0;

	printf("nbr: %d\n", nbr);
	nbr++;
}

int	main(int argc, char **argv)
{
	int fd;
	int i;

	i = 1;
	if (argc != 3)
		return (1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		printf("Error opening '%s' file!\n", argv[1]);
		return (1);
	}
	//
	i = 0;
	while (i < atoi(argv[2]))
	{
		static_test(atoi(argv[2]));
		i++;
	}
	printf("Valor de 'fd': %i\n", fd);
	if ((close(fd)) < 0)
	{
		printf("Error closing '%s' file!\n", argv[1]);
		return (1);
	}
	return (0);
}

