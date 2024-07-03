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

# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(char const *, ...);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_itoa_for_i(int n);
char	*ft_malloc(int n, int size);
#endif
