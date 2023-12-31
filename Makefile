# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 12:48:20 by gmorais-          #+#    #+#              #
#    Updated: 2024/01/03 18:44:43 by gsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra -lreadline -L ./libft -lft -g

INC		=	inc/minishell.h
SRC		=	src/minishell.c \
			src/signals.c \
			src/parse/lexer.c \
			src/parse/parse_red.c \
			src/parse/parse_utils.c \
			src/parse/parse_var.c \
			src/parse/parse.c \
			src/redir/redir.c \
			src/redir/redir_utils.c \
			src/executor/executor.c \
			src/executor/utils_executor.c\
			src/executor/utils_executor_2.c\
			src/builtins/func_pwd.c \
			src/builtins/func_echo.c \
			src/builtins/func_env.c \
			src/copy_env/copy_env.c \
			src/builtins/func_exec.c \
			src/builtins/find_builtin.c \
			src/builtins/func_cd.c \
			src/builtins/func_exit.c \
			src/builtins/func_unset.c \
			src/builtins/func_export.c \
			

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C ./libft
			@$(CC) $(SRC) $(FLAGS) -o $(NAME)

.c.o:
			@$(CC) -c $< -o $@

clean:
			@make clean -C ./libft
			@rm -rf $(OBJ)

fclean:		clean
			@make fclean -C ./libft
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
