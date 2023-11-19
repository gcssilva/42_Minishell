/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:18:39 by gsilva            #+#    #+#             */
/*   Updated: 2023/11/18 21:18:38 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

t_data	*data(void)
{
	static t_data	_data;
	
	return(&_data);
}

int	err_code = 0;

static void	print_struc(void)
{
	int	i;
	int	j;

	i = -1;
	printf("n_cmd: %i\n", data()->n_cmd);
	while (++i < data()->n_cmd)
	{
		printf("cmd %i: %s\n", i + 1, data()->cmds[i].cmd);
		j = -1;
		printf("args:\n");
		while (data()->cmds[i].arg[++j])
			printf("%s\n", data()->cmds[i].arg[j]);
		j = -1;
		printf("in:\n");
		while (data()->cmds[i].in[++j])
			printf("%s\n", data()->cmds[i].in[j]);
		j = -1;
		printf("out:\n");
		while (data()->cmds[i].out[++j])
			printf("%s\n", data()->cmds[i].out[j]);
		j = -1;
		printf("append:\n");
		while (data()->cmds[i].ap[++j])
			printf("%s\n", data()->cmds[i].ap[j]);
		j = -1;
		printf("delimiter:\n");
		while (data()->cmds[i].delimiters[++j])
			printf("%s\n", data()->cmds[i].delimiters[j]);
	}
}

int	main(void)
{
	char	*a;

	while(1)
	{
		a = readline("minishell:");
		add_history(a);
		n_cmds(a);
		if (lexer(a))
			parse_input(a);
		print_struc();
		free(a);
	}
}
