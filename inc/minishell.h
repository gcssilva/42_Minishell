#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_cmd
{
	char	*in[10];
	char	*out[10];
	char	*ap[10];
	char	*delimiters[10];
	char	*cmd;
	char	**arg;
}	t_cmd;

typedef struct s_data
{
	int		n_cmd;
	t_cmd	**cmds;
	char	**env;
}	t_data;

t_data	*data(void);

//builtins
void	find_builtins(char **cmd, char ***env, int flag);
void	func_pwd(void);
void	func_echo(char **cmd);
void	func_cd(char **line, char **env);
void	func_env(char **env);
void	func_unset(char **line, char ***env);
void	func_export(char **line, char ***env);
void	func_exit(char **line, char **env);
void	func_exec(char **line, char **env);

//executor
void	executer(char *cmd, char *arg, char ***env);

//parse
void	parse_input(char *input);
void	n_cmds(char	*input);
int		check_quotes(char *input);
int		ft_isblank(int c);
char	*cjoin(char **str, char c);
void	split_cmd(char *str, int *flag);
void	quote_join(char **cmd, char *input, int *i);


#endif