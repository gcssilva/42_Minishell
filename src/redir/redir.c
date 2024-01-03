/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:47:58 by gmorais-          #+#    #+#             */
/*   Updated: 2024/01/03 17:16:19 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	check_outfile(char *red, int flag);
void	check_infile(char *red);
void	check_heredoc(char *delimiter);
void	redirct(t_cmd *cmds);
void	do_heredoc(char *delimiter);

void	check_outfile(char *red, int flag)
{
	int	out;

	if (flag == 1)
		out = open(red, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		out = open(red, O_WRONLY | O_CREAT | O_TRUNC, 0777);
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

void	check_infile(char *red)
{
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

void	check_heredoc(char *delimiter)
{
	pid_t	pid;

	sig(3);
	if (!delimiter)
		return ;
	pid = fork();
	if (pid < 0)
		perror("error: fork");
	if (pid == 0)
	{
		sig(2);
		do_heredoc(delimiter);
	}
	else
	{
		waitpid(pid, 0, 0);
		sig(1);
	}
}

void	do_heredoc(char *delimiter)
{
	char	*input;

	(data()->tmp_f) = open(".tmp_f.txt", O_WRONLY | O_CREAT | O_APPEND, 0777);
	dup2(data()->std_fd[0], STDIN_FILENO);
	dup2(data()->std_fd[1], STDOUT_FILENO);
	while (1)
	{
		input = readline("> ");
		if (!input)
		{
			write(1, "heredoc delimited by eof\n", 26);
			exit(clean_all());
		}
		else if (!*input)
			continue ;
		else if (!ft_strncmp(delimiter, input, ft_strlen(delimiter))
			&& ((ft_strlen(delimiter)) == ft_strlen(input)))
			exit(clean_all());
		else
		{
			write(data()->tmp_f, input, ft_strlen(input));
			write(data()->tmp_f, "\n", 1);
			input = 0;
		}
	}
	exit(clean_all());
}

void	redirct(t_cmd *cmds)
{
	int		i;

	i = -1;
	while (cmds->red[++i])
	{
		if (!ft_strncmp(cmds->order[i], "in", 2))
			check_infile(cmds->red[i]);
		else if (!ft_strncmp(cmds->order[i], "out", 3))
			check_outfile(cmds->red[i], 0);
		else if (!ft_strncmp(cmds->order[i], "ap", 2))
			check_outfile(cmds->red[i], 1);
		else
			check_infile(".tmp_f.txt");
	}
}
