#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

//A struct s_cmd guarda as informacoes de 1 comando ate o proximo pipe ou ate o fim do input
//a variavel *delimiters[] representa um array de delimitadores de heredoc '<<'
//a variavel *cmd contem apenas o nome do comando
//a variavel **arg representa um array de argumentos passados ao comando (arg[0] sempre contem o nome do comando)

typedef struct	s_cmd
{
	int		index;
	char	*red[10];
	char	*order[10];
	char	*delimiters[10];
	char	*cmd;
	char	*arg[10];
}	t_cmd;

typedef struct s_data
{
	int		n_cmd;
	char	**copy_env;
	int		std_fd[2];
	int		last_fd[2];
	t_cmd	*cmds;
}	t_data;

t_data	*data(void);

//builtins
void	find_builtins(char cmd, int flag);
void	func_pwd(void);
void	func_echo(char **cmd);
void	func_cd(char **line, char **env);
void	func_env(char **env);
void	func_unset(char **line, char ***env);
void	func_export(char **line, char ***env);
void	func_exit(char **line, char **env);
void	func_exec(char **line, char **env);
void	just_one_cmd(char **copy_env);

//executor
void	executer(void);
void	redirct(t_cmd cmds, int *fd);

//parse
void	parse_input(char *input);
void	n_cmds(char	*input);
int		check_quotes(char *input);
int		ft_isblank(int c);
int		ft_isredir(int c);
int		split_cmd(char *str, int flag);
char	*quote_join(char *cmd, char *input, int *i);
void	copy_var(char *cmd, char *var);
void	exp_var(char *cmd, char *input, int *i);
int		check_pipes(char *input);
int		lexer(char *input);
char	*cjoin(char *str, char c);

#endif
