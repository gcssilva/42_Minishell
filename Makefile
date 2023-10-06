NAME	=	minishell
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra -lreadline -L ./libft -lft
SRC		=	main.c
OBJ		=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
			make -C ./libft
			$(CC) $(SRC) $(FLAGS) -o $(NAME)

all:		$(NAME)

clean:
			make clean -C ./libft
			rm -f $(OBJ)

fclean:		clean
			make fclean -C ./libft
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re