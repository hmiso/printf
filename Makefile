# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/18 20:15:21 by hmiso             #+#    #+#              #
#    Updated: 2020/07/22 19:00:20 by hmiso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
OBJ_FILES = ft_printf.o \
			ft_heks_print.o \
			ft_pointer_print.o \
			ft_procent_print.o \
			ft_string_print.o \
			ft_unsigned_print.o \
			ft_decimail_print.o \
			ft_char_print.o \
			resurs_funk.o \
			pars_digit.o \
			resurs_print_heks.o \
			ft_puthex.o \
			ft_putchar_fd.o \
			ft_strlen.o \
			ft_putstr_fd.o \
			ft_putaddr_fd.o \
			count_hex.o \
			count_adr.o \
			ft_putnbr_fd.o \
			ft_isdigit.o \
			ft_atoi.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILES) libftprintf.h
	ar rc $(NAME) $(OBJ_FILES) $^
	ranlib $(NAME)


%.o: %.c 
	gcc -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(BONUSO)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: make fclean clean all re