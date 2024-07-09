#include "get_next_line.h" 

int	main (void)
{
	char	*to_print;
	int		fd;

	to_print = "";
	fd = open("fichero", O_RDONLY);
	while (to_print)
	{
		to_print = get_next_line(fd);
		printf("%s", to_print);
	}
}
