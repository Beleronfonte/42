# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 11:41:46 by ofernand          #+#    #+#              #
#    Updated: 2024/06/03 11:39:44 by ofernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprint.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SOURCES = 
BONUS_SOURCES = 

all: $(NAME)

OBJS = $(SOURCES:.c=.o)

BONUS_OBJS = $(BONUS_SOURCES:.c=.o)

$(NAME) : $(OBJS)
	ar crs $(NAME) $(OBJS)

%.o : %.c
	cc -c $(CFLAGS) $< -o $@

bonus: $(BONUS_OBJS)
	ar crs $(NAME) $^

clean: 
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
