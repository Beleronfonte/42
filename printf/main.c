#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	char a;
	void *ptr = &i;
	int	*qtr = &i;
	char *otr = &a;

	i = 4;
	ft_printf("probando a decir %p, %p, %p.", ptr, qtr, otr);
	printf("probando a decir %p, %p, %p", ptr, qtr, otr);
}
