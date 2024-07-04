# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 10:26:01 by ofernand          #+#    #+#              #
#    Updated: 2024/04/09 10:27:09 by ofernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
OBJ_DIR = obj
INC = header.h
OBJS = main.o basic_ft.o find_and_print_ft.o
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS) $(INC)
	@cc $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o : ./%.c
	mkdir $(OBJ_DIR)
	@cc -c $(CFLAGS) $< -o $@

clean: 
	@rm -r  $(OBJ_DIR) $(NAME)

fclean: clean
