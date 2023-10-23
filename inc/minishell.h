#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include <errno.h>

//builtins
void	find_builtins(int fd);
void	func_pwd(int fd);
void	func_echo(char **cmd, int fd);

//parse
void	parse_input(char *input);

#endif