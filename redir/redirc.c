/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:47:58 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/20 14:27:07 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	put_outfile(int *fd)
{
	int i;
	int	out;

	if (data()->cmds[i]->out[i] != NULL)
	{
		out= open(data()->cmds[i]->out[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (out == -1)
		{
			perror("error: open outfile");
			exit(1);
		}
		if (dup2(out, STDOUT_FILENO) == -1)
		{
			perror("error : dup2");
			exit(1);
		}
		close(fd);
	}
}

void	check_infile(int *fd)
{
	int	i;
	int	in;;

	i = 0;
	if (data()->cmds[i]->in[i] != NULL)
	{
		in = open(data()->cmds[i]->in[i], O_RDONLY, 0644);
		if (in == -1)
		{
			perror("error: open");
			exit(1);
		}
		if (dup2(in, STDIN_FILENO) == -1)
		{
			perror("error: dup2");
			exit(1);
		}
		close(fd);
	}
	create_pid(data()->cmds[i]->cmd, fd, 0);
	check_outfile(fd);
}

void	redirct(void)
{
	int	fd[2];
	
	if (pipe(fd) == -1)
	{
		perror("error: pipe");
		exit(1);
	}
	check_infile(fd);
}
