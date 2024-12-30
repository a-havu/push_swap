# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 12:34:40 by ahavu             #+#    #+#              #
#    Updated: 2024/12/30 14:08:22 by ahavu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES_PATH = /sources

HEADERS_PATH = /headers

SOURCES = 	check_args.c operations_a.c operations_b.c operations_both.c \
			main.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all:

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all