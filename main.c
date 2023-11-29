/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:18:39 by gsilva            #+#    #+#             */
/*   Updated: 2023/11/29 14:20:47 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int exit_status = -1;

t_data	*data(void)
{
	static t_data	_data;
	
	return(&_data);
}

void	clean_struct(void)
{
	int	i;
	int	j;

	i = -1;
	while(++i < data()->n_cmd)
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
	copy_env(env);
	while(1)
	{
		sig(0);
		input = readline("minishell~> ");
		if (!input)
			break ;
		if (!*input)
			continue ;
		add_history(input);
		data()->std_fd[0] = dup(STDIN_FILENO);
		data()->std_fd[1] = dup(STDOUT_FILENO);
		n_cmds(input);
		if (lexer(input))
		{
			parse_input(input);
			data()->last_fd[0] = -1;
			executer();
		}
		free(input);
		remove(".temp_file.txt");
	}
	return (data()->exit_status);
}
