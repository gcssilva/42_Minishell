# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 12:48:20 by gmorais-          #+#    #+#              #
#    Updated: 2023/11/26 17:08:43 by gsilva           ###   ########.fr        #
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
SRC		=	main.c \
			signals.c \
			parse/parse.c \
			parse/parse_utils.c \
			redir/redirc.c \
			executor/executer.c \
			executor/utils_executer.c \
			builtins/func_pwd.c \
			builtins/func_echo.c \
			builtins/func_env.c \
			copy_env/copy_env.c \
			builtins/func_exec.c \
			builtins/find_builtin.c \
			builtins/func_cd.c \
			builtins/func_exit.c \
			builtins/func_unset.c \
			#builtins/func_export.c \#
			

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C ./libft
			@$(CC) $(SRC) $(FLAGS) -o $(NAME)

.c.o:
			@$(CC) $(FLAGS) -c $< -o $@

clean:
			@make clean -C ./libft
			@rm -rf $(OBJ)

fclean:		clean
			@make fclean -C ./libft
			@rm -f $(NAME)

re:			fclean all
			valgrind $(VAL) ./$(NAME)

.PHONY:		all clean fclean re
