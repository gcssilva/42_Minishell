/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:47:58 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/20 16:45:42 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	check_outfile(char *red, int *fd, int flag)
{
	int i;
	int	out;

	if (flag == 1)
		out= open(red, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		out= open(red, O_WRONLY | O_CREAT | O_TRUNC, 0777);
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
	close(out);
}

void	check_infile(char *red, int *fd)
{
	int	i;
	int	in;

	in = open(red, O_RDONLY, 0777);
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
	close(in);
}

void	redirct(t_cmd cmds, int *fd)
{
	int	i;

	i = -1;
	while (cmds.red[--i])
	{
		if (ft_strncmp(cmds.order[i], "in", 2))
			check_infile(cmds.red[i],fd);
		else if (ft_strncmp(cmds.order[i], "out", 3))
			check_outfile(cmds.red[i], fd, 0);
		else
			check_outfile(cmds.red[i], fd, 1);
	}
}
