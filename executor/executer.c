/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:46:36 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/20 14:34:14 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* em obras
nao sei oq fazer mais aqui
a principio a ideia esta posta
finalmente sem erros de codigo(modo burro) */

#include "../inc/minishell.h"

void	my_second_child(char cmd, int *fd)
{
	if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("error : dup2 in second child");
		close(fd[0]);
		close(fd[1]);
	}
	close(fd[0]);
	close(fd[1]);
	if (is_path(cmd) == 1)
	{
		find_builtins(cmd, 1);
		return ;
	}
	find_builtins(cmd, 0);
	return ;
}

void	my_first_child(char cmd, int *fd)
{
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("error : dup2 in first child");
		close(fd[1]);
	}
	close(fd[1]);
	if (is_path(cmd) == 1)
	{
		find_builtins(cmd, 1);
		return ;
	}
	find_builtins(cmd, 0);
	return ;
}

void	creat_pid(char *cmd, int *fd, int flag)
{
	pid_t	pid;

	if ((pid = fork()) < 0)
		perror("error: fork");
	if (pid == 0 && flag == 0)
		my_first_child(cmd, fd);
	else if (pid == 0 && flag == 1)
		my_second_child(cmd, fd);

}

void	pipe_create(int i, int flag, int *fd)
{
	if (data()->cmds[i]->cmd != NULL && data()->cmds[i]->arg != NULL)
	{
		if (pipe(fd) == -1)
		{
			t_putstr_fd("Error: ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr("\n");
		}
		while (data()->cmds[i++]->cmd != NULL && data()->cmds[i++]->arg != NULL)
		{
			if (flag == 0)
			{
				creat_pid(data()->cmds[i]->cmd, fd, 0);
				waitpid(-1, NULL, 0);
				flag = 1;
			}
			else if (flag == 1)
			{
				creat_pid(data()->cmds[i]->cmd, fd, 1);
				waitpid(-1, NULL, 0);
			}
		}
		close(fd[1]);
		close(fd[0]);
	}
}

void	executer(void)
{
	t_data	*n_cmd;
	int	i;
	int flag;
	int	fd[2];
	
	i = 0;
	flag = 0;
	if (n_cmd == 1)
	{
		just_one_cmd(data()->cmds[i]->cmd, data()->cmds[i]->arg, data()->copy_env);
		return ;
	}
	if (is_redirec() == 1)
	{
		redirct();
		return ;
	}
	pipe_create(i, flag, fd);
	return ;
}
