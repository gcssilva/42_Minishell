NAME	=	minishell
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra -lreadline -L ./libft -lft -fdiagnostics-color=always -g
INC		=	inc/minishell.h
SRC		=	main.c \
			parse/parse.c \

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
