# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srayees <srayees@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by yourlogin         #+#    #+#              #
#    Updated: 2025/08/11 11:54:10 by srayees          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_printf.c \
		ft_print_char.c \
		ft_print_str.c \
		ft_print_ptr.c \
		ft_print_nbr.c \
		ft_print_unsigned.c \
		ft_print_hex.c \
		main.c

OBJS = $(SRCS:.c=.o)

HEADERS = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
  