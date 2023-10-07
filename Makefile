NAME	=	minishell
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra -lreadline -L ./libft -lft
SRC		=	main.c

all:		$(NAME)


$(NAME):	
			@make -C ./libft
			@$(CC) $(SRC) $(FLAGS) -o $(NAME)

clean:
			@make clean -C ./libft
			@rm -f $(NAME)

fclean:		clean
				make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re
