# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 11:41:46 by ofernand          #+#    #+#              #
#    Updated: 2024/05/02 13:44:12 by ofernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SOURCES = ft_atoi.c	ft_bzero.c ft_isalpha.c	ft_calloc.c	ft_isalnum.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
	ft_memset.c ft_memcpy.c ft_memmove.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strdup.c ft_striteri.c ft_strlen.c \
	ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	ft_substr.c ft_tolower.c ft_toupper.c

all: $(NAME)

OBJS = $(SOURCES:.c=.o)

$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS)
	@echo "objects were created"
	@echo "everything went well"

%.o : %.c
	@cc -c $(CFLAGS) $< -o $@

clean: 
	@$(RM) $(OBJS)
	@echo "objects removed successfully"

fclean: clean
	@$(RM) $(NAME)
	@echo "everything is clean now"

re: fclean all

.PHONY: all clean fclean re
