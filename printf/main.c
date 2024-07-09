/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:28:34 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/06 07:33:56 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stddef.h>
#include <limits.h>

int	ft_printf(const char *str, ...);

int main(void)
{
	char			*word;
	void			*nb;
	int				entero;
	unsigned int	unsign;
	unsigned int	num;
	int				total_format;
	int				total_verdadero;
	int				value;
	char			letter;
	
	ft_printf("Probando %%c:\n");
	letter = 'P';
	total_format = ft_printf("Hola %c \n", letter);
	ft_printf("El size es: %d\n", total_format);
	total_verdadero = printf("Hola %c \n", letter);
	printf("El size verdadero es: %d\n\n", total_verdadero);
	
	ft_printf("Probando %%s:\n");
	word = "";
	total_format = ft_printf("Hola %s \n", word);
	ft_printf("El size es: %d\n", total_format);
	total_verdadero = printf("Hola %s \n", word);
	printf("El size verdadero es: %d\n\n", total_verdadero);

	ft_printf("Probando %%p:\n");
	value = 42;
	nb = &value;
	total_format = ft_printf("Hola %p \n", nb);
	ft_printf("El size es: %d\n", total_format);
	total_verdadero = printf("Hola %p \n", nb);
	printf("El size verdadero es: %d\n\n", total_verdadero);

	ft_printf("Probando %%i:\n");
	entero = 042;
	total_format = ft_printf("Hola %i \n", entero);
	ft_printf("El size es: %d\n", total_format);
	total_verdadero = printf("Hola %i \n", entero);
	printf("El size verdadero es: %d\n\n", total_verdadero);	
	
	ft_printf("Probando %%d:\n");
	total_format = ft_printf("Hola %d \n", entero);
	ft_printf("El size es: %d\n", total_format);
	total_verdadero = printf("Hola %d \n", entero);
	printf("El size verdadero es: %d\n\n", total_verdadero);

	ft_printf("Probando %%d MAX:\n");
	num = 42;
	total_format = ft_printf("Hola %d \n", INT_MAX);
	ft_printf("El size es: %d\n", total_format);
	total_verdadero = printf("Hola %d \n", INT_MAX);
	printf("El size verdadero es: %d\n\n", total_verdadero);

	ft_printf("Probando %%d MIN:\n");
	num = 42;
	total_format = ft_printf("Hola %d \n", INT_MIN);
	ft_printf("El size es: %d\n", total_format);
	total_verdadero = printf("Hola %d \n", INT_MIN);
	printf("El size verdadero es: %d\n\n", total_verdadero);

	unsign = -42;
	total_format = ft_printf("Hola %u \n", unsign);
	ft_printf("El size es: %d\n", total_format);
	total_verdadero = printf("Hola %u \n", unsign);
	printf("El size verdadero es: %d\n\n", total_verdadero);

	ft_printf("Probando %%u MAX:\n");
	num = 42;
	total_format = ft_printf("Hola %u \n", UINT_MAX);
	ft_printf("El size es: %d\n", total_format);
	total_verdadero = printf("Hola %u \n", UINT_MAX);
	printf("El size verdadero es: %d\n\n", total_verdadero);

	ft_printf("Probando %%x:\n");
	num = 42;
	total_format = ft_printf("Hola %x \n", num);
	ft_printf("El size es: %d\n", total_format);
	total_verdadero = printf("Hola %x \n", num);
	printf("El size verdadero es: %d\n\n", total_verdadero);

	ft_printf("Probando %%X:");
	total_format = ft_printf("Hola %X \n", num);
	ft_printf("El size es: %d\n", total_format);
	total_verdadero = printf("Hola %X \n", num);
	printf("El size verdadero es: %d\n\n", total_verdadero);

	ft_printf("Probando NULL con p:\n");
	total_format = ft_printf("Hola %p\n", NULL);
	ft_printf("El size es: %d\n", total_format);
	total_verdadero = printf("Hola %p\n", NULL);
	printf("El size verdadero es: %d\n\n", total_verdadero);

	ft_printf("Probando NULL con s:\n");
	total_format = ft_printf("Hola %s\n", NULL);
	ft_printf("El size es: %d\n", total_format);
	//total_verdadero = printf("Hola %s\n", NULL);
	//printf("El size verdadero es: %d\n\n", total_verdadero);

	ft_printf("Probando dos iguales:\n");
	total_format = ft_printf("Hola %s %s\n", "Patri", "Manzanas");
	ft_printf("El size es: %d\n", total_format);
	total_verdadero = printf("Hola %s %s\n", "Patri", "Manzanas");
	printf("El size verdadero es: %d\n\n", total_verdadero);
	
	ft_printf("Probando dos diferentes:\n");
	total_format = ft_printf("Hola %s %d\n", "Patri", 42);
	ft_printf("El size es: %d\n", total_format);
	total_verdadero = printf("Hola %s %d\n", "Patri", 42);
	printf("El size verdadero es: %d\n", total_verdadero);

	return (0);
}
