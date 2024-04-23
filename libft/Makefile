# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 11:41:46 by ofernand          #+#    #+#              #
#    Updated: 2024/04/23 13:20:02 by ofernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SOURCES = ft_atoi.c\
	ft_bzero.c\
	ft_isalpha.c\
	ft_isalnum.c\ 
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memset.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strchr.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_tolower.c\
	ft_toupper.c
OBJS = $(SOURCES:.c=.o)

$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS)

%.o : %.c
	@cc -c $(CFLAGS) $< -o $@

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
