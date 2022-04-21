# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schung <schung@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 18:44:32 by schung            #+#    #+#              #
#    Updated: 2022/04/21 20:18:26 by schung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = headers/minishell.h

SRC = minishell.c \

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra

CC = gcc $(CFLAGS)

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

REMOVE = rm -f

%.o: %.c $(HEADER)
	$(CC) -I $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -I $(HEADER) $(OBJ) -Llibft -lft -ltermcap -o $(NAME)
	@echo "$(LMAGENTA)[INFO] [$(NAME)] created"

clean:
	@$(REMOVE) $(OBJ)
	@echo "$(YELLOW)[INFO] Removed [$(NAME)] objects"

fclean: clean
	@$(REMOVE) $(NAME) $(OBJ)
	@make fclean -C libft
	@echo "$(YELLOW)[INFO] [$(NAME)] and objects removed"

re: fclean all

.PHONY: all clean fclean re

#COLOURS
NOCOLOR=\033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
LMAGENTA= \033[1;35m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
LIGHTGRAY=\033[0;37m
DARKGRAY=\033[1;30m
LIGHTRED=\033[1;31m
LIGHTGREEN=\033[1;32m
LIGHTBLUE=\033[1;34m
LIGHTPURPLE='\033[1;35m
LIGHTCYAN=\033[1;36m
WHITE=\033[1;37m
