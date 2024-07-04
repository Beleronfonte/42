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
	@ar crs $(NAME) $(OBJS)
	@echo "objects were created"
	@echo "$(NAME) created successfully"

%.o : %.c
	@cc -c $(CFLAGS) $< -o $@

bonus: $(BONUS_OBJS)
	@ ar crs $(NAME) $^
	@echo "bonus objects were created"
	@echo "bonus functions added to $(NAME)"

clean: 
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "objects removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "everything is clean now"

re: fclean all

.PHONY: all bonus clean fclean re
