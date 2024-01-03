/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:49:32 by gsilva            #+#    #+#             */
/*   Updated: 2024/01/03 17:21:00 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void    fake_hd(char *del)
{
    char   *input;

	dup2(data()->std_fd[0], STDIN_FILENO);
	dup2(data()->std_fd[1], STDOUT_FILENO);
    while (1)
	{
		input = readline("> ");
		if (!input)
		{
			write(1, "heredoc delimited by eof\n", 26);
			exit (clean_all());
		}
		else if (!ft_strncmp(del, input, ft_strlen(del))
			&& ((ft_strlen(del)) == ft_strlen(input)))
			exit (clean_all());
	}
	exit (0);
}

void check_fake_hd(char *del)
{
	pid_t	pid;

	sig(3);
	if (!del)
		return ;
	pid = fork();
	if (pid < 0)
		perror("error: fork");
	if (pid == 0)
	{
		sig(2);
		fake_hd(del);
	}
	else
	{
		waitpid(pid, 0, 0);
		sig(1);
	}
}
