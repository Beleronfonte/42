/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_print_ft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:12:33 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/08 15:59:57 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_big_numbers(int mod_length, char *to_read, char *to_print)
{
	if (mod_length == 4)
		to_print = ft_strstr(to_read, "1000");
	else if (mod_length == 7)
		to_print = ft_strstr(to_read, "1000000");
	else if (mod_length == 10)
		to_print = ft_strstr(to_read, "1000000000");
	else if (mod_length == 13)
		to_print = ft_strstr(to_read, "1000000000000");
	else if (mod_length == 16)
		to_print = ft_strstr(to_read, "1000000000000000");
	else if (mod_length == 19)
		to_print = ft_strstr(to_read, "1000000000000000000");
	else if (mod_length == 22)
		to_print = ft_strstr(to_read, "1000000000000000000000");
	else if (mod_length == 25)
		to_print = ft_strstr(to_read, "1000000000000000000000000");
	else if (mod_length == 28)
		to_print = ft_strstr(to_read, "1000000000000000000000000000");
	else if (mod_length == 31)
		to_print = ft_strstr(to_read, "1000000000000000000000000000000");
	else if (mod_length == 34)
		to_print = ft_strstr(to_read, "1000000000000000000000000000000000");
	else if (mod_length == 37)
		to_print = ft_strstr(to_read, "1000000000000000000000000000000000000");
	ft_write_number_name(to_print);
}

void	ft_units(int mod_length, char *number, char *to_read, char *to_print)
{
	if (number[0] == '0')
		return ;
	else
	{
		to_print = ft_strstr(to_read, &number[0]);
		ft_write_number_name(to_print);
		if (mod_length > 3 && (mod_length -1) % 3 == 0)
			ft_big_numbers(mod_length, to_read, to_print);
	}
}

void	ft_tens(char *number, char *to_read, char *to_print, int i)
{
	char	to_search[2];

	if (number[0] == '0')
		return ;
	if (number[0] == '1')
	{
		to_search[0] = number[0];
		to_search[1] = number[1];
		to_print = ft_strstr(to_read, to_search);
		i++;
	}
	else
	{
		to_search[0] = number[0];
		to_search[1] = '0';
		to_print = ft_strstr(to_read, to_search);
	}
	ft_write_number_name(to_print);
}

void	ft_hundreds(char *number, char *to_read, char *to_print)
{
	if (number[0] == '0')
		return ;
	to_print = ft_strstr(to_read, "100");
	ft_write_number_name(to_print);
}

void	ft_zero(char *number, char *to_read, char *to_print)
{
	to_print = ft_strstr(to_read, &number[0]);
	ft_write_number_name(to_print);
}
