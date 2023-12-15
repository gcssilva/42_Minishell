/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:18:39 by gsilva            #+#    #+#             */
/*   Updated: 2023/12/15 18:21:31 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

t_data	*data(void);
void	clean_struct(void);

int	g_sig = 0;

t_data	*data(void)
{
	static t_data	_data;

	return (&_data);
}

void	clean_struct(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data()->n_cmd)
	{
		j = -1;
		while (data()->cmds[i].arg[++j])
			free(data()->cmds[i].arg[j]);
		j = -1;
		while (data()->cmds[i].red[++j])
			free(data()->cmds[i].red[j]);
		j = -1;
		while (data()->cmds[i].order[++j])
			free(data()->cmds[i].order[j]);
		free(data()->cmds[i].cmd);
	}
	free(data()->cmds);
}

int	main(int ac, char **av, char **env)
{
	char	*input;

	(void)ac;
	(void)av;
	data()->std_fd[0] = dup(STDIN_FILENO);
	data()->std_fd[1] = dup(STDOUT_FILENO);
	copy_env(env);
	data()->exit_status = 0;
	while (1)
	{
		sig(0);
		input = readline("minishell~> ");
		if (!input)
		{
			printf("exit\n");
			return (0);
		}
		if (!*input)
			continue ;
		add_history(input);
		n_cmds(input);
		if (lexer(input))
		{
			parse_input(input);
			data()->last_fd[0] = -1;
			executor();
		}
		free(input);
		remove(".temp_file.txt");
	}
	return (data()->exit_status);
}
