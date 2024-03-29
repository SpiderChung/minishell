# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schung <schung@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 18:43:30 by schung            #+#    #+#              #
#    Updated: 2022/09/24 19:04:23 by schung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

LIB_DIR		=	./libft
SRCS		=	${shell find ./src -name "*.c"}
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

HEADER		=	-I./inc/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		=	-Wall -Wextra -Werror -I ~/.brew/opt/readline/include/
RDL			= 	-lreadline
# RDL			= 	-lreadline -L ~/.brew/opt/readline/lib
RM			=	rm -f

.PHONY:		all clean fclean re bonus rebonus norm

all:		$(NAME)

$(NAME):	$(OBJS) inc
			@#echo "\033[0;32m[$(NAME)] compiling.\033[0m"
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)/libft.a -o $(NAME) $(RDL)
			@#clear
			@echo "\033[0;32m[$(NAME)] compiled.\033[0m"

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)

clean:
			@make clean -C $(LIB_DIR)
			@$(RM) $(OBJS)
			@echo "\033[32m[$(NAME)] removed object files.\033[0m"

fclean:		clean
			@make fclean -C $(LIB_DIR)
			@$(RM) $(NAME)
			@echo "\033[32m[$(NAME)] removed executable files.\033[0m"

re:			fclean all

bonus:		all

rebonus:	re 

norm:
			norminette
