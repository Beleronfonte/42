#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("probando a decir %s. %%. %i.", "HOLA MUNDO", 99997);
	printf("probando a decir %s, %i", "HOLA MUNDO", 99997);
}
