# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 11:41:46 by ofernand          #+#    #+#              #
#    Updated: 2024/07/08 16:29:02 by ofernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprint.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SOURCES = chars_and_base10.c ft_printf.c hex_base.c 

all: $(NAME)

OBJS = $(SOURCES:.c=.o)

$(NAME) : $(OBJS)
	ar crs $(NAME) $^

%.o : %.c ft_printf.h Makefile
	gcc -c $(CFLAGS) $< -o $@

clean: 
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
