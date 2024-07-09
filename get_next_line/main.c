#include "get_next_line.h" 

int	main (void)
{
	char	*to_print;
	int		fd;
	int		i;

	i = 0;
	fd = open("fichero", O_RDONLY);
	while (i < 12)
	{
		to_print = get_next_line(fd);
		printf("%s", to_print);
		free(to_print);
		i++;
	}
}
