/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:30:22 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/10 17:09:40 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_line_len(char *map)
{
	int	i;
	int	line_length;

	i = 0;
	while (map[i] != '\n' && map[i] != '\0')
		i++;
	i++;
	line_length = 0;
	while (map[i] != '\n' && map[i] != '\0')
	{
		i++;
		line_length++;
	}
	return (line_length);
}

int	ft_valid_file(char *map, char *symbol)
{
	if (ft_valid_map(map) == 1)
		return (1);
	if (ft_valid_char(symbol) == 1)
		return (1);
	else
		return (0);
}

int	ft_valid_map(char *map)
{
	int	line_length;

	line_length = ft_line_len(map);
	if (line_length < 1)
		return (1);
	if (ft_equal_lines(map, line_length) == 1)
		return (1);
	else
		return (0);
}

int	ft_equal_lines(char *map, int line_length)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != '\n' && map[i] != '\0')
		i++;
	i++;
	while (map[i] != '\0')
	{
		j = 0;
		while (map[i] != '\n' && map[i] != '\0')
		{
			i++;
			j++;
		}
		if (j != line_length)
			return (1);
		if (map[i] == '\n')
			i++;
	}
	return (0);
}

int	ft_valid_char(char *symbol)
{
	if (symbol[0] == symbol[1] || symbol[1] == symbol[2]
		|| symbol [0] == symbol[2])
		return (1);
	if (!symbol[0] || !symbol[1] || !symbol[2])
		return (1);
	else
		return (0);
}
