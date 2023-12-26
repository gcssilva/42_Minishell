# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 12:48:20 by gmorais-          #+#    #+#              #
#    Updated: 2023/12/22 16:15:17 by gsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra -lreadline -L ./libft -lft -g
INC		=	inc/minishell.h
SRC		=	minishell.c \
			signals.c \
			parse/lexer.c \
			parse/parse_red.c \
			parse/parse_utils.c \
			parse/parse_var.c \
			parse/parse.c \
			redir/redir.c \
			executor/executor.c \
			executor/utils_executor.c\
			executor/utils_executor_2.c\
			builtins/func_pwd.c \
			builtins/func_echo.c \
			builtins/func_env.c \
			copy_env/copy_env.c \
			builtins/func_exec.c \
			builtins/find_builtin.c \
			builtins/func_cd.c \
			builtins/func_exit.c \
			builtins/func_unset.c \
			builtins/func_export.c \
			

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME): $(OBJ)
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
