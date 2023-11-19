# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 12:48:20 by gmorais-          #+#    #+#              #
#    Updated: 2023/11/18 18:10:47 by gsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra -lreadline -L ./libft -lft -fdiagnostics-color=always -g
INC		=	inc/minishell.h
SRC		=	main.c \
			parse/parse.c \
			parse/parse_utils.c \
			#builtins/find_builtin.c	builtins/func_cd.c builtins/func_echo.c builtins/func_env.c \
			builtins/func_exec.c builtins/func_exit.c builtins/func_export.c builtins/func_pwd.c \
			builtins/func_unset.c \

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	
			@make -C ./libft
			@$(CC) $(SRC) $(FLAGS) -o $(NAME)

.c.o:
			@$(CC) $(FLAGS) -c $< -o $@

clean:
			@make fclean -C ./libft

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
