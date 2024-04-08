/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:25 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/07 20:45:35 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	*ft_write_number_name(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && src[i] != ':')
		i++;
	if (src[i] == ':')
		i++;
	while (src[i] != '\0' && src[i] == ' ')
		i++;
	while (src[i] != '\0' && src[i] >= 32 && src[i] <= 126)
	{
		write(1, &src[i], 1);
		i++;
	}
	return (0);
}

void	ft_print_whole_name(int length, char *number, char *to_read)
{
	char	*to_print;
	int		i;

	to_print = (char *)malloc(sizeof(char) * 20);
	if (!to_print)
	{
		write(2, "Error\n", 6);
		return ;
	}
	i = 0;
	if (length == 1 && number[0] == '0')
		ft_zero(&number[i], to_read, to_print);
	while (number[i] != '\0')
	{
		if ((length -1 - i) % 3 == 0)
			ft_units(length - i, &number[i], to_read, to_print);
		if ((length -1 - i) % 3 == 1)
			ft_tens(&number[i], to_read, to_print, i);
		if ((length -1 - i) % 3 == 2)
			ft_hundreds(length - i, &number[i], to_read, to_print);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	free(to_print);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	size_to_find;

	i = 0;
	j = 0;
	size_to_find = 0;
	while (to_find[j] != '\0')
		j++;
	if (to_find[0] == 0)
		return (&str[0]);
	size_to_find = j;
	while (str[i] != '\0')
	{
		j = 0;
		if (to_find[0] == str[i])
		{
			while (to_find[j] == str[i + j] && j < size_to_find)
				j++;
			if (j == size_to_find)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

void	ft_choosen_dict(char *dict, char *number)
{
	int		length;
	int		fd;
	char	*to_read;

	to_read = (char *)malloc(sizeof(char) * 900);
	if (!to_read)
	{
		write(2, "Error\n", 6);
		return ;
	}
	length = 0;
	while (number[length])
		length++;
	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Dict Error\n", 11);
		return ;
	}
	else
		read(fd, to_read, 900);
	ft_print_whole_name(length, number, to_read);
	free(to_read);
}

int	validparameter(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}
