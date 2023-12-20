/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:47:58 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/20 14:36:26 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	check_outfile(char *red, int flag);
void	check_infile(char *red);
void	check_heredoc(char *delimiter);
void	redirct(t_cmd *cmds);

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
	int		i;
	char	*input;

	i = 1;
	sig(2);
	data()->temp_file = open(".temp_file.txt", O_WRONLY | O_CREAT | O_APPEND, 0777);
	while (i)
	{
		input = readline("> ");
		printf("%s\n", input);
		if (!input)
		{
			write(1, "heredoc delimited by eof\n", 26);
			i = 0;
		}
		else if (!ft_strncmp(delimiter, input, ft_strlen(delimiter))
			&& ((ft_strlen(delimiter)) == ft_strlen(input)))
			i = 0;
		else
		{
			write(data()->temp_file, input, ft_strlen(input));
			write(data()->temp_file, "\n", 1);
			free(input);
			input = 0;
		}
	}
	free(input);
	close(data()->temp_file);
	check_infile(".temp_file.txt");
	sig(1);
}

void	redirct(t_cmd *cmds)
{
	int	i;

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
		{
			remove(".temp_file.txt");
			check_heredoc(cmds->red[i]);
		}
	}
}
