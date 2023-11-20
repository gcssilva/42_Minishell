/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:46:36 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/20 18:01:23 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* em obras
nao sei oq fazer mais aqui
a principio a ideia esta posta
finalmente sem erros de codigo(modo burro) */

#include "../inc/minishell.h"

void	my_child(t_cmd cmds, int *fd)
{
	if (data()->last_fd[0] != -1)
	{
		dup2(data()->last_fd[0], STDIN_FILENO);
		close(data()->last_fd[0]);
		close(data()->last_fd[1]);
	}
	else
		dup2(data()->std_fd[0], STDIN_FILENO);
	close(fd[0]);
	if (cmds.index < data()->n_cmd)
		dup2(fd[1], STDOUT_FILENO);
	else
		dup2(data()->std_fd[1], STDOUT_FILENO);
	redirct(cmds, fd);
	if (is_path(cmds.cmd) == 1)
		find_builtins(cmds.cmd, 1);
	else
		find_builtins(cmds.cmd, 0);
	return ;
}

void	creat_pid(t_cmd cmds, int *fd)
{
	pid_t	pid;

	if ((pid = fork()) < 0)
		perror("error: fork");
	if (pid == 0)
		my_child(cmds, fd);
	else
	{
		if (data()->last_fd[0] != -1)
		{
			close(data()->last_fd[0]);
			close(data()->last_fd[1]);
		}
		data()->last_fd[0] = fd[0];
		data()->last_fd[1] = fd[1];
	}
}

void	pipe_create(int i, int flag, int *fd)
{
	while (++i < data()->n_cmd)
	{
		if (pipe(fd) == -1)
		{
			t_putstr_fd("Error: ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr("\n");
			return ;
		}
		creat_pid(data()->cmds[i], fd);
		waitpid(-1, NULL, 0);
		close(fd[0]);
		close(fd[1]);
	}
}

void	executer(void)
{
	t_data	*n_cmd;
	int	i;
	int flag;
	int	fd[2];
	
	i = -1;
	flag = 0;
	pipe_create(i, flag, fd);
	return ;
}
