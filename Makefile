# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 12:34:40 by ahavu             #+#    #+#              #
#    Updated: 2025/01/23 15:40:19 by ahavu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES_PATH = sources/
LIBFT_PATH = libft_plus/

SOURCES = 	$(SOURCES_PATH)check_args.c $(SOURCES_PATH)init_nodes.c \
			$(SOURCES_PATH)init_nodes_b.c $(SOURCES_PATH)operations_a.c \
			$(SOURCES_PATH)operations_b.c $(SOURCES_PATH)operations_both.c \
			$(SOURCES_PATH)split_args.c $(SOURCES_PATH)push_swap.c \
			$(SOURCES_PATH)lst_utils.c $(SOURCES_PATH)stack_utils.c \
			$(SOURCES_PATH)sort_three.c $(SOURCES_PATH)sort_big.c \

OBJECTS = $(SOURCES:.c=.o)

HEADER = push_swap.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -g 
#-fsanitize=address

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_PATH)libft_plus.a -o $(NAME)

$(SOURCES_PATH)%.o: $(SOURCES_PATH)%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all