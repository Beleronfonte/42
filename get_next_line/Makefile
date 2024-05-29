# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 11:48:15 by ofernand          #+#    #+#              #
#    Updated: 2024/05/29 10:33:53 by ofernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SOURCES = get_next_line.c get_next_line_utils.c 
BONUS_SOURCES = 

all: $(NAME)

OBJS = $(SOURCES:.c=.o)

BONUS_OBJS = $(BONUS_SOURCES:.c=.o)

$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS)
	@echo "objects were created"
	@echo "libft.a created successfully"

%.o : %.c
	@cc -c $(CFLAGS) $< -o $@

bonus: $(BONUS_OBJS)
	@ ar crs $(NAME) $^
	@echo "bonus objects were created"
	@echo "bonus functions added to libft.a"

clean: 
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "objects removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "everything is clean now"

re: fclean all

.PHONY: all bonus clean fclean re
