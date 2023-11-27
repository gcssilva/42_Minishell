/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:18:39 by gsilva            #+#    #+#             */
/*   Updated: 2023/11/27 15:31:27 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int exit_status = -1;

t_data	*data(void)
{
	static t_data	_data;
	
	return(&_data);
}

// void	print_struc(void)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	printf("n_cmd: %i\n", data()->n_cmd);
// 	while (++i < data()->n_cmd)
// 	{
// 		printf("cmd %i: %s\n", i + 1, data()->cmds[i].cmd);
// 		j = -1;
// 		printf("args:\n");
// 		while (data()->cmds[i].arg[++j])
// 			printf("%s\n", data()->cmds[i].arg[j]);
// 		j = -1;
// 		printf("in:\n");
// 		while (data()->cmds[i].red[++j])
// 			printf("%s\n", data()->cmds[i].red[j]);
// 		j = -1;
// 		printf("out:\n");
// 		while (data()->cmds[i].order[++j])
// 			printf("%s\n", data()->cmds[i].order[j]);
// 		j = -1;
// 		printf("delimiter:\n");
// 		while (data()->cmds[i].delimiters[++j])
// 			printf("%s\n", data()->cmds[i].delimiters[j]);
// 	}
// }

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
	(void)	ac;
	(void)	av;
	copy_env(env);
	while(1)
	{
		input = readline("minishell:");
		add_history(input);
		data()->std_fd[0] = dup(STDIN_FILENO);
		data()->std_fd[1] = dup(STDOUT_FILENO);
		n_cmds(input);
		if (lexer(input))
		{
			parse_input(input);
			data()->last_fd[0] = -1;
		}
		executer();
		//clean_struct();
		free(input);
		remove(".temp_file.txt");
	}
	return (exit_status);
}
