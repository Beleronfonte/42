/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:26:33 by meghribe          #+#    #+#             */
/*   Updated: 2024/04/10 17:38:36 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_atoi(char *str);
int		ft_char(char *str, char *symbol);
int		ft_valid_file(char *map, char *symbol);
int		ft_valid_map(char *map);
int		ft_equal_lines(char *map, int line_length);
int		ft_valid_char(char *symbol);
int		ft_count(void);
int		ft_length(char *file_name);
char	*ft_filereader(char *file_name);
int		ft_backtracker(char **matrix, char empty, int *coord);
int		ft_sq_keeper(int x, int y, int *coord, int sq_size);
int		ft_sq_search(char *matrix, char empty);
int		ft_check_sq_column(char **matrix, char empty, int size);
int		ft_check_sq_line(char *matrix, char empty, int size);
void	ft_matrix_magic(char *map, char *symbol, int number);
void	ft_fill_matrix(char *map, char **matrix);
void	ft_change_matrix(char *matrix, int result_size, char full);
void	ft_print_matrix(char *matrix);
char	**ft_malloc_matrix(int length, int number);
