# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lylfergu <lylfergu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 13:41:46 by lylfergu          #+#    #+#              #
#    Updated: 2024/04/08 13:20:02 by ofernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
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
