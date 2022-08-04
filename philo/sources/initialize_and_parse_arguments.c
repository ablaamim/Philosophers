#include "../includes/philosophers.h"

/*
 * Parse arguments and error handling
*/

void	ft_parser(int argc, char **argv)
{
	int	i;
	int j;

	i = 0x1;
	j = 0x0;
	while (argv[i])
	{
		j = 0x0;
		if (!isdigit(argv[i][j++]))
		{
			write(2, "Error\n", sizeof("Error\n"));
			exit(EXIT_FAILURE);
		}
		printf("ARG[%d] => %s\n", i, argv[i]);
		i++;
	}
	if (argc > 6)
		write(2, MANY_ARGS, sizeof(MANY_ARGS));
	else if (argc <= 4)
		write(2, FEW_ARGS, sizeof(FEW_ARGS));
	else
		return ;
	exit(EXIT_FAILURE);
}

void	ft_parse_and_initialize(int argc, char **argv)
{
	ft_parser(argc, argv);
}
