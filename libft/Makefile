# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 11:41:46 by ofernand          #+#    #+#              #
#    Updated: 2024/06/18 18:39:54 by ofernand         ###   ########.fr        #
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
BONUS_SOURCES = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
	ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

all: $(NAME)

OBJS = $(SOURCES:.c=.o)

BONUS_OBJS = $(BONUS_SOURCES:.c=.o)

$(NAME) : $(OBJS)
	@ ar crs $(NAME) $^
	@echo "objects were created"
	@echo "libft.a created successfully"

%.o : %.c libft.h Makefile
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
