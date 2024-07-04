/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:34:04 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/10 17:40:21 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_backtracker(char **matrix, char empty, int *coord)
{
	int	x;
	int	y;
	int	sq_size;
	int	result_size;

	x = 0;
	y = 0;
	result_size = -1;
	while (matrix[x][y] == '\0')
	{
		while (matrix[x][y] == '\0')
		{
			if (matrix[x][y] == empty)
			{
				sq_size = ft_sq_search(&matrix[x][y], empty);
				if (sq_size > result_size)
					result_size = ft_sq_keeper(x, y, coord, sq_size);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (result_size);
}

int	ft_sq_keeper(int x, int y, int *coord, int sq_size)
{
	coord[0] = x;
	coord[1] = y;
	return (sq_size);
}

int	ft_sq_search(char *matrix, char empty)
{
	int	try_bigger;
	int	sq_size;
	int	is_square;

	try_bigger = 1;
	sq_size = 0;
	while (try_bigger)
	{
		is_square = ft_check_sq_column(&matrix, empty, sq_size);
		if (is_square == 0)
		{
			try_bigger = 1;
			sq_size++;
		}
		else
			try_bigger = 0;
	}
	return (sq_size);
}

int	ft_check_sq_column(char **matrix, char empty, int size)
{
	int	j;

	j = 0;
	while (matrix[0][j] && matrix[0][j] == empty && j < size)
	{
		if (ft_check_sq_line(&matrix[0][j], empty, size) == 0)
			j++;
		else
			return (1);
	}
	if (j < size)
		return (1);
	else
		return (0);
}

int	ft_check_sq_line(char *matrix, char empty, int size)
{
	int	i;

	i = 0;
	while (&matrix[i][0] && &matrix[i][0] == empty && i < size)
		i++;
	if (i < size)
		return (1);
	else
		return (0);
}
