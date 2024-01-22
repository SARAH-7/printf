# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 20:14:17 by sbakhit           #+#    #+#              #
#    Updated: 2024/01/21 21:11:30 by sbakhit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
SOURCES = \
	ft_printf.c ft_strlen.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunsigned_int.c\
	ft_putnbr_hex.c ft_putpointer.c ft_putnbr_hex_cap.c ft_atoi.c ft_itoa.c is_negative.c\

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb3
AR = ar

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -rcs $@ $?

test: $(NAME) main.c
	$(CC) -ggdb3 main.c $(NAME) -o test

bonus: all

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re