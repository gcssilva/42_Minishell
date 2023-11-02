# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 12:48:20 by gmorais-          #+#    #+#              #
#    Updated: 2023/10/24 15:52:19 by gmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra -lreadline -L ./libft -lft -fdiagnostics-color=always
INC		=	inc/minishell.h
SRC		=	main.c \
			parse/parse.c \
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
