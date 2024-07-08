/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:46:45 by ofernand          #+#    #+#             */
/*   Updated: 2024/06/03 12:37:40 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *, ...);
int		print_and_count(const char *str, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_itoa_for_i(int n);
char	*ft_calloc(int n, int size);
int		ft_utoa(unsigned int n);
int		ft_ltohex(unsigned long n, char *base);
int		ft_ptr_dir(void *ptr);
#endif
