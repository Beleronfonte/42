#include <stdio.h>

int	main(int ac, char **av, char **envp)
{
	char *a;

	while (*envp != 0)
	{
		a = *envp;
		printf("%s\n", a);
		envp++;
	}
	return (0);
}
