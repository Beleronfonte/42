/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:35:37 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/08 15:59:37 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_big_numbers(int mod_length, char *to_read, char *to_print);
void	ft_units(int mod_length, char *number, char *to_read, char *to_print);
void	ft_tens(char *number, char *to_read, char *to_print, int i);
void	ft_hundreds(char *nummber, char *to_read, char *to_print);
void	ft_zero(char *number, char *to_read, char *to_print);
int		*ft_write_number_name(char *src);
void	ft_print_whole_name(int length, char *number, char *to_read);
char	*ft_strstr(char *str, char *to_find);
void	ft_choosen_dict(char *dict, char *number);
int		validparameter(char *str);
