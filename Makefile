# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 12:48:20 by gmorais-          #+#    #+#              #
#    Updated: 2023/12/07 16:50:09 by gmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra -lreadline -L ./libft -lft -fdiagnostics-color=always -g

VAL		=	--leak-check=full \
			--show-leak-kinds=all \
			--log-file=valgrind_log.txt \
			--suppressions=readline.supp \
			--track-fds=yes

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
			executor/utils_executer.c\
			executor/utils_executer_2.c\
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
			valgrind $(VAL) ./$(NAME)

.PHONY:		all clean fclean re
