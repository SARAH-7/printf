# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 20:14:17 by sbakhit           #+#    #+#              #
#    Updated: 2024/01/27 13:11:46 by sbakhit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
SOURCES = \
	ft_printf.c ft_strlen.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunsigned_int.c\
	ft_putnbr_hex.c ft_putpointer.c ft_putnbr_hex_cap.c ft_atoi.c ft_itoa.c flag_space.c\
	flag_right_padding.c flag_alternate_form.c flag_precision.c flag_zero.c string_width.c\
	minimum_width.c precentage_format.c string_precision.c null_string_with_width.c\
	null_string.c negtaive_signed.c hex_length_counter.c putchar_counter.c putnbr_counter.c\
	putunsigned_counter.c flag_check.c puthex_counter.c puthex_cap_counter.c\
	string_flag_right_padding.c putnegative_and_flag_space.c flag_positive_sign.c num_precision.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -rcs $@ $?

bonus: all

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re