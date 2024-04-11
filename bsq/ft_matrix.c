/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:18:38 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/10 17:41:40 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	ft_matrix_magic(char *map, char *symbol, int number)
{
	int		coord[2];
	int		length;
	int		size;
	char	**matrix;

	length = ft_line_length(map);
	matrix = ft_malloc_matrix(length, number);
	ft_fill_matrix(map, matrix);
	size = ft_backtracker(matrix, &symbol[0], coord);
	ft_change_matrix(matrix[coord[0]][coord[1]], size, symbol[2]);
	ft_print_matrix(matrix);
	free(map);
}

void	ft_fill_matrix(char *map, char *matrix)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (map[i] != '\n')
		i++;
	i++;
	while (map[i] != '\0')
	{
		x = 0;
		while (map[i] != '\n' && map[i] != '\0')
		{
			matrix[x][y] = map[i];
			i++;
			x++;
		}
		i++;
		y++;
	}
}

void	ft_change_matrix(char *matrix, int result_size, char full)
{
	int	i;
	int	j;

	j = 0;
	while (j < result_size)
	{
		i = 0;
		while (i < result_size)
		{
			matrix[i][j] = full;
			i++;
		}
		j++;
	}
}

void	ft_print_matrix(char *matrix)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (matrix[x][y])
	{
		x = 0;
		while (matrix[x][y])
		{
			write(1, &matrix[x][y], 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
}

char	**ft_malloc_matrix(int length, int number)
{
	int		i;
	int		j;
	char	**matrix;

	matrix = (char **)malloc(length * sizeof(char *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < length)
	{
		matrix[i] = (char *)malloc(number * sizeof(char));
		if (!matrix[i])
		{
			j = 0;
			while (j < i)
			{
				free(matrix[j]);
				j++;
			}
			free(matrix);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}
